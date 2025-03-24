# Segregation Simulation
## Author
|Name|Student Number|
|-|-|
|Arthur Atangana|101005197|

[github repository](www.github.com/arthuratangana/segregation-simulation)
### Part 1

#### Introduction
The segregation model was first introduced by Thomas Schelling. His paper describes how population segregate over time based on their different characteristics. Examples of these characteristics could be age, language, income, sex and many more. This is the core idea that was implemented in this model and simulation, based on two groups with a distinct characteristic.
#### Model
The model consists of two groups. Group A (represented by 1) and Group B (represented by -1).
Using Moore Neighborhood of size 3X3, a cell will look at its neighbours and move to the first empty cell it can find if its current neighborhood has a majority of different cells relative to itself.
##### Rules
- For every cell with a value of 1, calculate the sum of its 3X3 moore neighbourhood (center cell excluded):
    * If Σ < -0.5 then the cell moves to the first available empty cell.
- For every cell with a value of -1, calculate the sum of its 3X3 moore neighbourhood (center cell excluded):
    * If Σ > -0.5 then the cell moves to the first available empty cell.

##### States
|Value|Meaning|
|-|-|
|0|Empty Cell|
|1|Group A|
|-1|Group B|

### Part 2 - Specification and Implementation
#### Cell-DEVS Formal Specification

$$ X = \emptyset $$
$$ Y = \emptyset $$
$$ S = {0, 1, -1} $$
delay = inertial
N = Moore's 3X3
d = 1
$ \tau = $
```c++
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
			if (state.value == 1.0){
				numA++;
			}
			else if (state.value == -1.0) {
				numB++;
			}
			state.value = 0.0; // The current position becomes empty
		}

		return state;
```
D = 1
$ \delta_{int} =  Cell DEVS specification$:
$ \delta_{ext} =  Cell DEVS specification$:
$ \lambda =  Cell DEVS specification$:

#### Test Frames and experiments
The segregation maps generated using the formal specification above showcase the behavior of the model under different starting conditions.

##### Experiment 1
In this experiment, Group A is the only one meant to move as the group B cells are already segregated. Group A are show exploring the map until they find the right spot.
![Experiment 1 Initial State](documentation/img/experiment_1_initial_state.png)
![Experiment 1 Final State](documentation/img/experiment_1_final_state.png)
##### Experiment 2
In this experiment, Group B is the only one meant to move as the group A cells are already segregated. Group B are show exploring the map until they find the right spot.
![Experiment 2 Initial State](documentation/img/experiment_2_initial_state.png)
![Experiment 2 Final State](documentation/img/experiment_2_final_state.png)
##### Experiment 3
In this experiment, Group B and Group A both need to move. They are show exploring the map until they find the right spot that fulfills the requirements.
![Experiment 3 Initial State](documentation/img/experiment_3_initial_state.png)
![Experiment 3 Final State](documentation/img/experiment_3_final_state.png)
##### Experiment 4
In this experiement, Only 1 valid spot exists for the group A cell that is needed to move. The cell should find the right spot that fulfills the requirement and stay there. Due to the simulation always processing the first iteration at t=0, the video is not able to show this process but the following images do.

![Experiment 4 Initial State](documentation/img/experiment_4_initial_state.png)
![Experiment 4 Final State](documentation/img/experiment_4_final_state.png)
##### Experiment 5
In this experiment, There is no valid spot that exists for the group A cell. The cell should be attempting to go to the same location infinitely. The final state reference images shows the last frame but in reality, the cell is attempting to go to a location.

![Experiment 5 Initial State](documentation/img/experiment_5_initial_state.png)
![Experiment 5 Final State](documentation/img/experiment_5_final_state.png)
##### Experiment 6
In this experiment, cells move in a pseudo random manner until they find a neighborhood that is properly segregated (50% majority). The group B (grey) is arranged in stripes while the red cells are trying to find a spot to congregagte. in the initial state, all groupA (red) cells must move and some groupB (grey) cells must move.

![Experiment 6 Initial State](documentation/img/experiment_6_initial_state.png)
![Experiment 6 Final State](documentation/img/experiment_6_final_state.png)

#### Conclusion
The segregation model showcases the natural segregation pattern that arises when cells attempt to be surrounded wit h at least 50% of similar cells. While this does not necessarily create uniform blocks and sometime simple neighborhoods where 1 of each coexists together, in most cases the cells aggregate into a large cluster of similar neighbours.
##### Potential improvements and remaining work
Since the model iterates and assign cells one at a time to the first empty cell, this means that the predetermination of the final state is set by the initial state. To further this model's complexity, a random distribution of cells upon a move would results in vastly different patterns. Another interesting option would be that when a cells decides to move, it randomly looks at empty cells, but only choses to move to that empty cell if it's neighborhood also satisfies the segregation principle of 50% or more similar neighbours.

