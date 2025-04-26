# Segregation Simulation
## Author
|Name|Student Number|
|-|-|
|Arthur Atangana|101005197|

[github repository](www.github.com/arthuratangana/segregation-simulation)
### Description
This model of segregation exists in two parts: the basic grid Cell-DEVS model, an initial first step into the modeling of internal segregation, and a second exploration using Asymmetric Cell-DEVS modeling to add complexity in our model. The two are separated in their respective directory.

### Running the model
- To run the grid Cell-DEVS:
    - run the run_experiments.sh script
    - To run a single experiment or custom configuration:
```bash
./cell-devs/bin/segregation -c path_to_config.json -t simulation_time_number -o path_to_output.csv
# example:
./cell-devs/bin/segregation -c config/cell-devs/experiment_1_config.json -s 500 -o logs/cell-devs/experiment_1_log.csv
```
- To run the asymmetric Cell-DEVS:
    - run the run_asymmetric.sh script
    - To run a single experiment or custom configuration:
```bash
./asymmetric-cell-devs/bin/segregation -c path_to_config.json -t simulation_time_number -o path_to_output.csv
# example:
./asymmetric-cell-devs/bin/segregation -c config/asymmetric-cell-devs/experiment_1_config.json -s 500 -o logs/asymmetric-cell-devs/experiment_1_log.csv
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
├── build
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
│   ├── asymmetric-cell-devs
│   │   ├── default_config.json
│   │   ├── experiment_1_config.json
│   │   ├── experiment_2_config.json
│   │   ├── experiment_3_config.json
│   │   ├── experiment_4_config.json
│   │   ├── experiment_5_config.json
│   │   ├── experiment_6_config.json
│   │   ├── ratio_10_config.json
│   │   ├── ratio_25_config.json
│   │   └── ratio_50_config.json
│   └── cell-devs
│       ├── default_config.json
│       ├── experiment_1_config.json
│       ├── experiment_2_config.json
│       ├── experiment_3_config.json
│       ├── experiment_4_config.json
│       ├── experiment_5_config.json
│       └── experiment_6_config.json
├── documentation
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
│   ├── Segregation_Term_Project_Report.pdf
│   └── videos
│       ├── experiment_1.webm
│       ├── experiment_2.webm
│       ├── experiment_3.webm
│       ├── experiment_4.webm
│       ├── experiment_5.webm
│       └── experiment_6.webm
├── logs
│   ├── asymmetric-cell-devs
│   │   ├── default_log.csv
│   │   ├── experiment_1_log.csv
│   │   ├── experiment_2_log.csv
│   │   ├── experiment_3_log.csv
│   │   ├── experiment_4_log.csv
│   │   ├── experiment_4_report_log.csv
│   │   ├── experiment_5_log.csv
│   │   ├── ratio_10_log.csv
│   │   ├── ratio_25_log.csv
│   │   └── ratio_50_log.csv
│   └── cell-devs
│       ├── experiment_1_log.csv
│       ├── experiment_2_log.csv
│       ├── experiment_3_log.csv
│       ├── experiment_4_log.csv
│       ├── experiment_5_log.csv
│       └── experiment_6_log.csv
├── presentation.md
├── readme.md
├── run_asymmetric.sh
└── run_experiments.sh
```

