#!/bin/bash

# run experiments
./bin/segregation -c experiment_1_config.json -s 500 -o experiment_1_log.csv
./bin/segregation -c experiment_2_config.json -s 500 -o experiment_2_log.csv
./bin/segregation -c experiment_3_config.json -s 500 -o experiment_3_log.csv
./bin/segregation -c experiment_4_config.json -s 500 -o experiment_4_log.csv
./bin/segregation -c experiment_5_config.json -s 500 -o experiment_5_log.csv
./bin/segregation -c experiment_6_config.json -s 500 -o experiment_6_log.csv
