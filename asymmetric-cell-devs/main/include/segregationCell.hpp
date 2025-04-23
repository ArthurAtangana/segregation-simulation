#ifndef SEGREGATION_CELL_HPP
#define SEGREGATION_CELL_HPP

#include <iostream>
#include <random>
#include <cmath>
#include <nlohmann/json.hpp>
#include <cadmium/modeling/celldevs/asymm/cell.hpp>
#include <cadmium/modeling/celldevs/asymm/config.hpp>
#include <unordered_map>
#include <vector>
#include "segregationState.hpp"

using namespace cadmium;
using namespace cadmium::celldevs; 

class segregation : public AsymmCell<segregationState, double> {
	std::string cellID;
	double ratio;
	public:
	static inline std::unordered_map<std::string, double> cellsAssignment;
	segregation(const std::string& id, 
			const std::shared_ptr<const AsymmCellConfig<segregationState, double>>& config
		  ): AsymmCell<segregationState, double>(id, config) {
		cellID = id;
		config ->rawCellConfig.at("ratio").get_to(ratio);
	}

	[[nodiscard]] segregationState localComputation(segregationState state, const std::unordered_map<std::string, NeighborData<segregationState, double>>& neighborhood) const override {


		// trying out a cell for at least 5 time units before looking to move
		state.timePassed++;
		if (state.timePassed < 5) {
			return state;
		}

		// assign value if there is one to be assigned, and add cellID:0 pair if not already in the map
		if (state.value == 0.0) {
			state.value = cellsAssignment[cellID]; // assign value
			cellsAssignment[cellID] = 0.0; //reset cell assignment tracker
			if (state.value != 0){
				state.timePassed = 0; // restart the counter for the cell
			}
			return state;
		}

		// check if cell needs to move
		if (cellNeedsToMove(state, neighborhood)){
			moveCell(state);
			// reset state of the cell
			state.value = 0.0;
			return state;
		} else {
			return state;
		}
	}

	[[nodiscard]] double outputDelay(const segregationState& state) const override {
		return 1.0;
	}

	[[nodiscard]] bool cellNeedsToMove(const segregationState& state, const std::unordered_map<std::string, NeighborData<segregationState, double>>& neighborhood) const {

		int similarNeighbors = 0;
		int totalNeighbors = 0;

		if (state.isValuableLocation) {
			totalNeighbors++; //  cell counts again (valuable location adds +1 to the total count (negates 1 different neighbor)
		}

		// Count the number of different-type neighbors
		for (const auto& [neighborId, neighborData] : neighborhood) {
			double neighborValue = neighborData.state->value;
			if (neighborValue != 0.0) { // Ignore empty cells
				totalNeighbors++;
				if (state.value != neighborValue){
					similarNeighbors++;
				}
			}
		}
		if (totalNeighbors == 0) {
			return true; // empty neighborhood. cell wants friends.
		} else if ((double)similarNeighbors/totalNeighbors >= ratio) {
			return false; // enough are similar to the cell, no need to move
		} else {
			return true; // cell needs to move
		}
	}
	void moveCell(const segregationState& state) const {
		// add cell current value to a random empty cell in the cellAssignments map
		std::vector<std::string> zeroKeys;

		// Collect keys with value == 0
		for (const auto& [key, val] : cellsAssignment) {
			if (val == 0) {
			zeroKeys.push_back(key);
			}
		}

		if (zeroKeys.empty()) {
			return;  // No suitable key found
		}

		// Choose a random key from those
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, zeroKeys.size() - 1);

		std::string chosenKey = zeroKeys[dist(gen)];
		cellsAssignment[chosenKey] = state.value;

	}
};

#endif //SEGREGATION_CELL_HPP
