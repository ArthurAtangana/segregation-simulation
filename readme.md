# Segregation Simulation
## Author
|Name|Student Number|
|-|-|
|Arthur Atangana|101005197|

[github repository](www.github.com/arthuratangana/segregation-simulation)

### Running the model
- To run all experiments, run the run_experiments.sh script
- To run a single experiment or custom configuration:
```bash
./bin/segregation -c path_to_config.json -s simulation_time_number -o path_to_output.csv
```
- example:
```bash
./bin/segregation -c config/experiment_1_config.json -s 500 -o logs/experiment_1_log.csv
```

### Project Structure:

```bash
├── asymmetric-cell-devs
│   ├── build_sim.sh
│   ├── CMakeLists.txt
│   └── main
│       ├── CMakeLists.txt
│       ├── include
│       │   ├── segregationCell.hpp
│       │   └── segregationState.hpp
│       └── main.cpp
├── cell-devs
│   ├── build_sim.sh
│   ├── CMakeLists.txt
│   └── main
│       ├── CMakeLists.txt
│       ├── include
│       │   ├── segregationCell.hpp
│       │   └── segregationState.hpp
│       └── main.cpp
├── config
│   ├── default_config.json
│   ├── experiment_1_config.json
│   ├── experiment_2_config.json
│   ├── experiment_3_config.json
│   ├── experiment_4_config.json
│   ├── experiment_5_config.json
│   └── experiment_6_config.json
├── documentation
│   ├── final_report.md
│   ├── final_report.pdf
│   ├── img
│   │   ├── experiment_1_final_state.png
│   │   ├── experiment_1_initial_state.png
│   │   ├── experiment_2_final_state.png
│   │   ├── experiment_2_initial_state.png
│   │   ├── experiment_3_final_state.png
│   │   ├── experiment_3_initial_state.png
│   │   ├── experiment_4_final_state.png
│   │   ├── experiment_4_initial_state.png
│   │   ├── experiment_5_final_state.png
│   │   ├── experiment_5_initial_state.png
│   │   ├── experiment_6_final_state.png
│   │   └── experiment_6_initial_state.png
│   ├── presentation.odp
│   └── videos
│       ├── experiment_1.webm
│       ├── experiment_2.webm
│       ├── experiment_3.webm
│       ├── experiment_4.webm
│       ├── experiment_5.webm
│       └── experiment_6.webm
├── logs
│   ├── experiment_1_log.csv
│   ├── experiment_2_log.csv
│   ├── experiment_3_log.csv
│   ├── experiment_4_log.csv
│   ├── experiment_5_log.csv
│   └── experiment_6_log.csv
├── presentation.md
├── readme.md
└── run_experiments.sh
```

