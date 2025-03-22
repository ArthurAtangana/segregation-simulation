#ifndef SEGREGATION_CELL_HPP
#define SEGREGATION_CELL_HPP

#include <random>
#include <cmath>
#include <nlohmann/json.hpp>
#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include <cadmium/modeling/celldevs/grid/config.hpp>
#include "segregationState.hpp"

using namespace cadmium::celldevs;

class segregation : public GridCell<segregationState, double> {
	public:
	segregation(const std::vector<int>& id, 
			const std::shared_ptr<const GridCellConfig<segregationState, double>>& config
		  ): GridCell<segregationState, double>(id, config) { }



	[[nodiscard]] segregationState localComputation(segregationState state, const std::unordered_map<std::vector<int>, NeighborData<segregationState, double>>& neighborhood) const override {
		if (state.value == 0.0) {
			return state; // Empty cells do not move
		}

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
			std::vector<int> newLocation = findRandomEmptySpot(neighborhood);

			if (!newLocation.empty()) {
				state.value = 0.0; // The current position becomes empty
			}
		}

		return state;

	}

	[[nodiscard]] double outputDelay(const segregationState& state) const override {
		return 1.0;
	}
	private:
	std::vector<int> findRandomEmptySpot(const std::unordered_map<std::vector<int>, NeighborData<segregationState, double>>& neighborhood) const {
        
		std::vector<std::vector<int>> emptyCells;

		for (const auto& [neighborId, neighborData] : neighborhood) {
			if (neighborData.state->value == 0.0) { // Find empty spots
				emptyCells.push_back(neighborId);
			}
		}

		if (emptyCells.empty()) return {}; // No empty spots available

		// Select a random empty cell
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, emptyCells.size() - 1);	
		return emptyCells[dis(gen)];
	}
};

#endif //SEGREGATION_CELL_HPP
