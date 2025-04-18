#ifndef SEGREGATION_CELL_HPP
#define SEGREGATION_CELL_HPP

#include <iostream>
#include <random>
#include <cmath>
#include <nlohmann/json.hpp>
#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include <cadmium/modeling/celldevs/grid/config.hpp>
#include <vector>
#include "segregationState.hpp"

using namespace cadmium::celldevs; class segregation : public GridCell<segregationState, double> {
	public:

	static inline int numA = 0;
	static inline int numB = 0;
	static inline std::vector<int> emptyCells;

	segregation(const std::vector<int>& id, 
			const std::shared_ptr<const GridCellConfig<segregationState, double>>& config
		  ): GridCell<segregationState, double>(id, config) {
	}


	[[nodiscard]] segregationState localComputation(segregationState state, const std::unordered_map<std::vector<int>, NeighborData<segregationState, double>>& neighborhood) const override {

		if (state.value == 0.0) {
			if (numA > 0) {
				state.value = 1.0;
				numA--;
				return state;
			}
			else if (numB > 0) {
				state.value = -1.0;
				numB--;
				return state;
			}
		}

		// Move if more than 50% of non-empty neighbors are different
		if (validCell(state, neighborhood)) {
			if (state.value == 1.0){
				numA++;
			}
			else if (state.value == -1.0) {
				numB++;
			}
			state.value = 0.0; // The current position becomes empty
		}

		return state;

	}

	[[nodiscard]] double outputDelay(const segregationState& state) const override {
		return 1.0;
	}

	bool validCell(const segregationState& state, const std::unordered_map<std::vector<int>, NeighborData<segregationState, double>>& neighborhood) const {
		int differentNeighbors = 0;
		int totalNeighbors = 0;

		// Count the number of different-type neighbors
		for (const auto& [neighborId, neighborData] : neighborhood) {
			double neighborValue = neighborData.state->value;

			if (neighborValue != 0.0) { // Ignore empty cells
				totalNeighbors++;
				if ((state.value > 0 && neighborValue < 0) || (state.value < 0 && neighborValue > 0)) {
					differentNeighbors++;
				}
			}
		}
		// Move if more than 50% of non-empty neighbors are different
		if (totalNeighbors > 0 && (double)differentNeighbors / totalNeighbors > 0.5) {
			return true;
		} else {
			return false;
		}
	}
};

#endif //SEGREGATION_CELL_HPP
