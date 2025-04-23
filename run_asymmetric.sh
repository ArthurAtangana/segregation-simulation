#!/bin/bash
echo "Asymmetric Cell-DEVS simulation: Segregation model"
echo "--------------------------------------------------"
cd asymmetric-cell-devs
# build asymmetric-cell-devs simulation
echo "Building cadmium project"
echo "--------------------------------------------------"
./build_sim.sh
# run experiments
echo "--------------------------------------------------"
echo "Running default experiment"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/default_config.json -t 500 -o ../logs/asymmetric-cell-devs/default_log.csv
echo "Running experiment 1"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_1_config.json -t 100 -o ../logs/asymmetric-cell-devs/experiment_1_log.csv
echo "Running experiment 2"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_2_config.json -t 500 -o ../logs/asymmetric-cell-devs/experiment_2_log.csv
echo "Running experiment 3"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_3_config.json -t 500 -o ../logs/asymmetric-cell-devs/experiment_3_log.csv
echo "Running experiment 4"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_4_config.json -t 500 -o ../logs/asymmetric-cell-devs/experiment_4_log.csv
