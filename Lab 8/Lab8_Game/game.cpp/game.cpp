// mouse maze game gameflow
// Sidney Raabe 10/28/2022

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
	srand(time(nullptr));
	
	// set room and walls
	Room currentRoom = startRoom; 
	Room nextRoom;
	RoomPair maze[numWalls];
	clearWalls(maze);
	// assign numWalls walls to maze array
	build(maze);

	//printMaze(maze); cout << endl;
	
	bool gameAborted = false;
	RoomPair currentMove; 
	while (true) {
		// clear screen between moves
		// later, mouse location will update on UI
		system("CLS");

		// old gross text maze
		//printMaze(maze); 
		
		
		// prompt user for intput
		cout << endl;

		// prints visual maze with updating mouse
		printMazeUI(maze, currentRoom);

		cout << "Current location: "; printRoom(currentRoom); cout << endl;
		nextRoom = nextMove(currentRoom);

		// user has quit if nextMove returns invalid room
		// check if user quit
		if (matchRoom(invalidRoom, nextRoom)) {
			gameAborted = true;
			break;
		}

		currentMove.one = currentRoom;
		currentMove.two = nextRoom;

		// move failed, by hitting wall or no change
		if (checkMaze(maze, currentMove) != -1 || matchRoom(currentRoom, nextRoom)) {
			cout << "\nA wall blocks your path.\n";
			system("pause");
			continue;
		}
		// win condition
		else if (matchRoom(cheeseRoom, nextRoom))
			break;
		// move success
		else
			currentRoom = nextRoom;
	}
	// display win message if user didn't hit q
	if (!gameAborted) {
		printWinScreen();
	}

	return 0;
}