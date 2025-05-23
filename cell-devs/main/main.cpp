#include "include/segregationState.hpp"
#include "nlohmann/json.hpp"
#include <cadmium/modeling/celldevs/grid/coupled.hpp>
#include <cadmium/simulation/logger/csv.hpp>
#include <cadmium/simulation/logger/stdout.hpp>
#include <cadmium/simulation/root_coordinator.hpp>
#include <limits>
#include <chrono>
#include <fstream>
#include <string>
#include <iostream>

#include "include/segregationCell.hpp"

using namespace cadmium::celldevs;
using namespace cadmium;

std::shared_ptr<GridCell<segregationState, double>> addGridCell(const coordinates & cellId, const std::shared_ptr<const GridCellConfig<segregationState, double>>& cellConfig) {
	auto cellModel = cellConfig->cellModel;

	if (cellModel == "segregation") {
		return std::make_shared<segregation>(cellId, cellConfig);
	} else {
		throw std::bad_typeid();
	}
}

int main(int argc, char ** argv) {

	std::string configFilePath = "config/segregation_config.json";
	std::string outputFilePath = "output/segregation_log.csv";
	double simTime = 100;
	bool cmd_out = false;

	for (int i = 1; i < argc; ++i){
		std::string arg = argv[i];
		// config file
		if (arg == "--config" || arg == "-c"){
			if (i + 1 < argc){
				configFilePath = argv[++i];
			}
			else {
				std::cout << "missing config paramenter" << std::endl;
				return 1;
			}
		}
		// sim time
		else if (arg == "--time" || arg == "-t"){
			if (i + 1 < argc){
				simTime = std::stod(argv[++i]);
			}
			else {
				std::cout << "missing simulation time paramenter" << std::endl;
				return 1;
			}
		}
		// output file
		else if (arg == "--output" || arg == "-o"){
			if (i + 1 < argc){
				if (std::string(argv[i+1]) == "cmd"){
					cmd_out = true;
					i++;
				} else {
					outputFilePath = argv[++i];
				}
			}
			else {
				std::cout << "missing outputFilePath paramenter" << std::endl;
				return 1;
			}
		}
		else {
			std::cout << "Invalid argument: " << arg << std::endl;
			return 1;
		}
	}
	auto model = std::make_shared<GridCellDEVSCoupled<segregationState, double>>("segregation", addGridCell, configFilePath);
	model->buildModel();
	
	auto rootCoordinator = RootCoordinator(model);
	if (cmd_out){
		rootCoordinator.setLogger<STDOUTLogger>(";");
	} else {
		rootCoordinator.setLogger<CSVLogger>(outputFilePath,";");
	}	
	rootCoordinator.start();
	rootCoordinator.simulate(simTime);
	rootCoordinator.stop();
}
