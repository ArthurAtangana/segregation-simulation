#!/bin/bash

# run experiments
./cell-devs/bin/segregation -c config/experiment_1_config.json -t 500 -o logs/experiment_1_log.csv
./cell-devs/bin/segregation -c config/experiment_2_config.json -t 500 -o logs/experiment_2_log.csv
./cell-devs/bin/segregation -c config/experiment_3_config.json -t 500 -o logs/experiment_3_log.csv
./cell-devs/bin/segregation -c config/experiment_4_config.json -t 500 -o logs/experiment_4_log.csv
./cell-devs/bin/segregation -c config/experiment_5_config.json -t 500 -o logs/experiment_5_log.csv
./cell-devs/bin/segregation -c config/experiment_6_config.json -t 500 -o logs/experiment_6_log.csv

# run asymmetric experiments
