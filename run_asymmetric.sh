#!/bin/bash
# build asymmetric-cell-devs simulation
./asymmetric-cell-devs/build_sim.sh
# run experiments
./asymmetric-cell-devs/bin/segregation -c config/asymmetric-cell-devs/experiment_1_config.json -t 500 -o logs/asymmetric-cell-devs/experiment_1_log.csv
# ./cell-devs/bin/segregation -c config/asymmetric-cell-devs/experiment_2_config.json -t 500 -o logs/asymmetric-cell-devs/experiment_2_log.csv
# ./cell-devs/bin/segregation -c config/asymmetric-cell-devs/experiment_3_config.json -t 500 -o logs/asymmetric-cell-devs/experiment_3_log.csv
# ./cell-devs/bin/segregation -c config/asymmetric-cell-devs/experiment_4_config.json -t 500 -o logs/asymmetric-cell-devs/experiment_4_log.csv
# ./cell-devs/bin/segregation -c config/asymmetric-cell-devs/experiment_5_config.json -t 500 -o logs/asymmetric-cell-devs/experiment_5_log.csv
# ./cell-devs/bin/segregation -c config/asymmetric-cell-devs/experiment_6_config.json -t 500 -o logs/asymmetric-cell-devs/experiment_6_log.csv
