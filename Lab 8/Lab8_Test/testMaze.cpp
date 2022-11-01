// tests maze function implementation
// Mikhail Nesterenko 10/21/2022,
// Sidney Raabe 10/25 - 10/28-2022

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	// set random seed
	srand(time(nullptr));

	//
	// first part: checking Room functions
	//

	// create a room
	Room myRoom;
	myRoom.x = 2;
	myRoom.y = 'b';

	// print Room
	cout << "myRoom, fixed location: "; printRoom(myRoom); cout << endl;

	// asks user for new adjacent room
	Room newMoveRoom = nextMove(myRoom);

	if (newMoveRoom.x != -1 && newMoveRoom.y != '*') {
		// display the move
		cout << "user selected adjacent room: "; printRoom(newMoveRoom); cout << endl;
		// a moved-in room may match previous if there is a wall between them
		if (matchRoom(myRoom, newMoveRoom)) cout << "myRoom is the same as newMoveRoom" << endl;

		//select and print fixed wall
		RoomPair myWall = { {2,'b'}, {2,'c'} };
		cout << "myWall, fixed location: "; printPair(myWall); cout << endl;

		//select and print a random wall
		myWall = pickWall();
		cout << "myWall, random location: "; printPair(myWall); cout << endl;

		// display user move as a pair
		RoomPair myMove;
		myMove.one = myRoom; myMove.two = newMoveRoom;
		printPair(myMove);

		if (matchPair(myWall, myMove))
			cout << "there is a wall between these two rooms" << endl; // move unsuccessful, no change
		else 
		{
			cout << "there is no wall between these two rooms" << endl;
			// move is successful, update user's location
			myRoom.x = newMoveRoom.x;
			myRoom.y = newMoveRoom.y;
		}

		// print new location
		cout << "my new location: ";  printRoom(myRoom);
		cout << endl;

		//
		// third part: check maze functions
		//

		// initialize maze array
		RoomPair myMaze[numWalls];
		clearWalls(myMaze);

		// display empty walls
		cout << "uninitialized maze walls: ";  printMaze(myMaze); cout << endl;

		// placing walls at random locations in the maze
		build(myMaze);

		// check user's move again, now to newly generated maze
		if (checkMaze(myMaze, myMove) != -1)
			cout << "there is a wall between these two rooms" << endl;
		else
			cout << "there is no wall between these two rooms" << endl;

		// display all maze walls
		cout << "built maze: ";  printMaze(myMaze); cout << endl;
	}
	return 0;
}