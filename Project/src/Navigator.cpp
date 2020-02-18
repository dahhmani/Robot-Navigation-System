#include "Navigator.h"

void fp::Navigator::drive(std::shared_ptr<fp::LandBasedRobot> robot)
{
	std::vector<fp::Cell> goals{ robot->maze.get_goals() };
	std::vector<fp::Cell> path;
	std::vector<char> actions;

	while (!isElementOf(robot->GetCell(), goals))
	{
		path = planPath(robot);
		actions = planActions(robot, path);

		for (int i = 0, j = 1; i < actions.size(); ++i)
		{
			auto [cell_front, cell_left, cell_right] = robot->GetSurroundingCells();

			if (actions[i] == Forward)
			{
				if (robot->maze.isWall(robot->GetCell(), cell_front))
					break;
				API::clearAllColor();
				highlightPath(robot, path, j++);
				robot->MoveForward();
			}
			else if (actions[i] == Left)
			{
				if (robot->maze.isWall(robot->GetCell(), cell_left))
					break;
				robot->TurnLeft();
			}
			else if (actions[i] == Right)
			{
				if (robot->maze.isWall(robot->GetCell(), cell_right))
					break;
				robot->TurnRight();
			}
			else if (actions[i] == Backward)
			{
				robot->TurnLeft(); 
				robot->TurnLeft();
			}
		}
	}
}

std::vector<fp::Cell> fp::Navigator::planPath(std::shared_ptr<fp::LandBasedRobot> robot)
{
	fp::Cell start_position = robot->GetCell();

	fp::Cell current_position = start_position;
	fp::Cell current_parent = robot->maze.get_start();

	std::vector<fp::Cell> neighbors;
	std::vector< std::vector<fp::Cell> > to_visit;
	std::vector< std::vector<fp::Cell> > visited;
	visited.resize(2);
	to_visit.resize(2);

	std::vector<Cell> path;
	fp::Maze current_maze = robot->maze;

	std::vector<fp::Cell> goals = current_maze.get_goals();

	while (!isElementOf(current_position, goals))
	{
		neighbors.clear();
		fp::Cell north_neighbor{ current_position.x,current_position.y + 1 };
		fp::Cell south_neighbor{ current_position.x,current_position.y - 1 };
		fp::Cell east_neighbor{ current_position.x + 1,current_position.y };
		fp::Cell west_neighbor{ current_position.x - 1,current_position.y };

		// search order: down, right, up, left
		if (current_maze.containCell(south_neighbor))
			neighbors.push_back(south_neighbor);
		if (current_maze.containCell(east_neighbor))
			neighbors.push_back(east_neighbor);
		if (current_maze.containCell(north_neighbor))
			neighbors.push_back(north_neighbor);
		if (current_maze.containCell(west_neighbor))
			neighbors.push_back(west_neighbor);

		//check if possible neighbors meet all criteria if so add to toVisit
		for (int i = 0; i < neighbors.size(); i++) {
			bool cond1 = !current_maze.isWall(current_position, neighbors[i]); //check if not wall
			bool cond2 = !isElementOf(neighbors[i], visited[0]); //check if not in visited already
			if (cond1 and cond2)
			{
				to_visit[0].push_back(neighbors[i]);
				to_visit[1].push_back(current_position);
			}
		}

		visited[0].push_back(current_position);
		visited[1].push_back(current_parent);

		//update current position and parent to first column in to_visit
		current_position = to_visit[0][0];
		current_parent = to_visit[1][0];
		//Delete first column of to_visit
		to_visit[0].erase(to_visit[0].begin());
		to_visit[1].erase(to_visit[1].begin());

		if (to_visit.size() == 0) {
			print("Unsolvable Maze");
			break;
		}
	}

	fp::Cell current_node = current_position;
	fp::Cell parent_node = current_parent;
	while (current_node != start_position)
	{
		path.push_back(current_node);
		for (int i = 0; i < visited[0].size(); i++) {
			if (parent_node == visited[0][i])
			{
				current_node = parent_node;
				parent_node = visited[1][i];
				break;
			}
		}
	}
	path.push_back(current_node);
	std::reverse(path.begin(), path.end());

	//if (path.empty()) exit(0);

	return path;
}

std::vector<char> fp::Navigator::planActions(std::shared_ptr<LandBasedRobot> robot, const std::vector<fp::Cell>& path) 
{
	std::vector<char> cardinal_actions;
	std::vector<char> robot_actions;

	for (int i = 0; i < path.size() - 1; i++) {
		fp::Cell c1 = path[i];
		fp::Cell c2 = path[i + 1];

		if ((c1.x == c2.x) && (c1.y < c2.y)) {
			cardinal_actions.push_back(fp::North);
		}
		else if ((c1.x < c2.x) && (c1.y == c2.y))
		{
			cardinal_actions.push_back(fp::East);
		}
		else if ((c1.x == c2.x) && (c1.y > c2.y))
		{
			cardinal_actions.push_back(fp::South);
		}
		else if ((c1.x > c2.x) && (c1.y == c2.y)) {
			cardinal_actions.push_back(fp::West);
		}
	}
	char current_direction = robot->GetDirection();
	for (int i = 0; i < cardinal_actions.size(); i++) {
		if (current_direction == cardinal_actions[i]) {
			robot_actions.push_back(Forward);
		}
		else if (current_direction == (cardinal_actions[i] + 3) % 4) {
			robot_actions.push_back(Right);
			robot_actions.push_back(Forward);
			current_direction = cardinal_actions[i];
		}
		else if (current_direction == (cardinal_actions[i] + 1) % 4) {
			robot_actions.push_back(Left);
			robot_actions.push_back(Forward);
			current_direction = cardinal_actions[i];
		}
		else {
			robot_actions.push_back(Backward);
			robot_actions.push_back(Forward);
			current_direction = cardinal_actions[i];
		}
	}

	return robot_actions;
}

bool fp::Navigator::isElementOf(const fp::Cell& c, const std::vector<fp::Cell>& path)
{
	for (auto cell : path)
		if (c == cell)
			return true;

	return false;
}

void fp::Navigator::highlightPath(std::shared_ptr<fp::LandBasedRobot> robot, const std::vector<fp::Cell>& path, int currentIndex)
{
	fp::Cell start{ robot->maze.get_start() };
	std::vector<fp::Cell> goals{ robot->maze.get_goals() };

	API::setColor(start.x, start.y, 'G');

	for (auto goal : goals)
		API::setColor(goal.x, goal.y, 'G');

	for (int i = currentIndex; i < path.size(); ++i)
		API::setColor(path[i].x, path[i].y, 'B');
}