// Sidney Raabe
// Mouse gameflow using classes
// 11/05/2022

#include <iostream>
#include "maze.hpp"

using std::cout; using std::cin; using std::endl;

int main() {
	srand(time(nullptr));
	// set up walls
	Maze myMaze;
	myMaze.start();
	myMaze.build();
	cout << "Walls: "; myMaze.print();

	// set up game variables
	Room invalid, myRoom, cheeseRoom, newMoveRoom;
	cheeseRoom.makeCheeseRoom();
	bool win = false;

	// main gameloop
	while (true)
	{
		myRoom = myMaze.getCurrentRoom();
		// check if previous move cause win
		if (matchRoom(myRoom, cheeseRoom))
		{
			win = true;	
			break;
		}
		// prompt move
		cout << "Your room: "; myRoom.print(); cout << endl;
		newMoveRoom = myRoom.nextMove();

		// check move against maze
		if (myMaze.move(newMoveRoom)) {
			// catch invalid room case, by "quit" selection
			if (matchRoom(newMoveRoom, invalid))
				break;
			cout << "Success." << endl;
		}
		else 
			cout << "Failed." << endl;
	}
	if (win) 
		cout << "You win!";
}