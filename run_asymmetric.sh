#!/bin/bash
echo "Asymmetric Cell-DEVS simulation: Segregation model"
echo "--------------------------------------------------"
cd asymmetric-cell-devs
# build asymmetric-cell-devs simulation
echo "Building cadmium project"
echo "--------------------------------------------------"
./build_sim.sh
echo "--------------------------------------------------"
# run experiments

# echo "Running default experiment"
# echo "--------------------------------------------------"
# ./bin/segregation -c ../config/asymmetric-cell-devs/default_config.json -t 500 -o ../logs/asymmetric-cell-devs/default_log.csv
echo "Running experiment 1"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_1_config.json -t 50 -o ../logs/asymmetric-cell-devs/experiment_1_log.csv
echo "Running walls experiment 2"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_2_config.json -t 500 -o ../logs/asymmetric-cell-devs/experiment_2_log.csv
echo "Running valuable location experiment 3"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_3_config.json -t 500 -o ../logs/asymmetric-cell-devs/experiment_3_log.csv
echo "Running valuable location experiment 4"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_4_config.json -t 500 -o ../logs/asymmetric-cell-devs/experiment_4_log.csv
echo "Running combined experiment 5"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/experiment_5_config.json -t 500 -o ../logs/asymmetric-cell-devs/experiment_5_log.csv
echo "Running 50% ratio experiment"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/ratio_50_config.json  -t 500 -o ../logs/asymmetric-cell-devs/ratio_50_log.csv
echo "Running 25% ratio experiment"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/ratio_25_config.json  -t 500 -o ../logs/asymmetric-cell-devs/ratio_25_log.csv
echo "Running 10% ratio experiment"
echo "--------------------------------------------------"
./bin/segregation -c ../config/asymmetric-cell-devs/ratio_10_config.json  -t 500 -o ../logs/asymmetric-cell-devs/ratio_10_log.csv
