# Robot Navigation in an Unknown Environment         			             
This robot navigation system was tested using [Micromouse Simulator](https://github.com/mackorone/mms). 
Breadth-first Search and Depth-first Search were applied to implement the path planning algorithm.
<p align="center">
  <img src="https://github.com/dahhmani/Robot-Navigation/blob/master/Project/Demo/MazeSolved.gif?raw=true">
</p>

## Setup
1. Clone this repository
2. Open the Simulator folder and launch the simulator ```mms.exe```
3. Set "Directory" to the path of ```src```
4. Set "Build Command" to 
```
g++ -std=c++17 -O2 -o ..\..\Simulator\a.exe API.cpp Main.cpp Maze.cpp Cell.cpp LandBasedRobot.cpp LandBasedTracked.cpp LandBasedWheeled.cpp Navigator.cpp
```
5. Set "Run Command" to ```a.exe```
6. Build the project and run it