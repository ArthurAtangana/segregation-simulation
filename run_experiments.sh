#!/bin/bash
# build cell-devs simulation
./cell-devs/build_sim.sh
# run experiments
./cell-devs/bin/segregation -c config/cell-devs/experiment_1_config.json -t 500 -o logs/cell-devs/experiment_1_log.csv
./cell-devs/bin/segregation -c config/cell-devs/experiment_2_config.json -t 500 -o logs/cell-devs/experiment_2_log.csv
./cell-devs/bin/segregation -c config/cell-devs/experiment_3_config.json -t 500 -o logs/cell-devs/experiment_3_log.csv
./cell-devs/bin/segregation -c config/cell-devs/experiment_4_config.json -t 500 -o logs/cell-devs/experiment_4_log.csv
./cell-devs/bin/segregation -c config/cell-devs/experiment_5_config.json -t 500 -o logs/cell-devs/experiment_5_log.csv
./cell-devs/bin/segregation -c config/cell-devs/experiment_6_config.json -t 500 -o logs/cell-devs/experiment_6_log.csv
