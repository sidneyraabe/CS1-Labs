// Function definitions for maze lab
// Sidney Raabe 10/25 - 10/28/2022

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;


//
// initialization functions
//


// sets every passed in room pair within array to -1,*
void clearWalls(RoomPair rooms[]) {
	for (int i = 0; i < numWalls; ++i) {
		rooms[i].two = rooms[i].one = invalidRoom;
	}
}

//generates a wall between two random rooms
const RoomPair pickWall() {
	//select a random location for the first room
	int x = rand() % mazeSize + 1;
	char y = rand() % mazeSize + 'a';

	//initialize rooms, b will be offset later
	Room a = { x, y };
	Room b = { x, y };

	//offset second room by 1 in some direction, in bounds of maze
	int direction = rand() % 4;
	switch (direction) {
	case (0): //up
		a.x != 1 ? b.x-- : b.x++;
		break;
	case (1): //down
		a.x != mazeSize ? b.x++ : b.x--;
		break;
	case (2): //left
		a.y != 'a' ? b.y-- : b.y++;
		break;
	case (3): //right
		a.y != 'a' + mazeSize - 1 ? b.y++ : b.y--;
		break;
	}

	RoomPair pair;
	pair.one = a;
	pair.two = b;

	return pair;
}

// returns true if the two given rooms are the same
bool matchRoom(const Room& first, const Room& second) {
	return first.x == second.x && first.y == second.y;
}

// returns true if two pairs of adjacent rooms are the same
bool matchPair(const RoomPair& first, const RoomPair& second) {
	return (matchRoom(first.one, second.one) && matchRoom(first.two, second.two) ||
		matchRoom(first.one, second.two) && matchRoom(first.two, second.one));
}

// returns the the index of a match, or -1 if no match							
int checkMaze(const RoomPair walls[], const RoomPair move) {
	for (int i = 0; i < numWalls; ++i) {
		if (matchPair(walls[i], move))
			return i;
	}
	return -1;
}

// places internal walls in random locations of the maze
void build(RoomPair mazeWalls[]) {
	RoomPair nextWall;
	for (int i = 0; i < numWalls; ++i) {
		nextWall = pickWall();
		// first wall must be new
		if (i == 0) {
			mazeWalls[0] = nextWall;
			continue;
		}
		// check every wall up to current index for matches
		bool previousWallMatch = false;
		for (int j = 0; j < i; ++j) {
			if (matchPair(mazeWalls[j], nextWall))
				previousWallMatch = true;
		}
		if (previousWallMatch) {
			i--;
			continue;
		}
		// nextWall must be a new wall
		mazeWalls[i] = nextWall;
	}
}


//
// display functions
//


// prints the location of the room
void printRoom(const Room& room) {
	cout << room.x << room.y;
}

// prints the locations of a pair of rooms
void printPair(const RoomPair& rooms) {
	printRoom(rooms.one);
	cout << '|';
	printRoom(rooms.two);
}

// prints the locations of all the internal walls of the maze
void printMaze(const RoomPair rooms[]) {
	for (int i = 0; i < numWalls; ++i) {
		printPair(rooms[i]);
		cout << ", ";
	}
}


//
// game functions
//


// asks the user an adjacent room to currentRoom to move
const Room nextMove(const Room& currentRoom) {
	Room nextRoom;
	char choice;

	// prompt user for move
	cout << "Enter a move: ";
	cin >> choice;


	nextRoom = currentRoom;
	choice = tolower(choice);

	// assume move is invalid
	bool moveHitsWall = true;

	switch (choice) {
	case ('u'):
		// passes if move is within bounds
		if (currentRoom.x != 1) {
			nextRoom.x = currentRoom.x - 1;
			moveHitsWall = false;
		}
		nextRoom.y = currentRoom.y;
		break;
	case ('d'):
		if (currentRoom.x != mazeSize) {
			nextRoom.x = currentRoom.x + 1;
			moveHitsWall = false;
		}
		nextRoom.y = currentRoom.y;
		break;
	case ('l'):
		if (currentRoom.y != 'a') {
			nextRoom.y = currentRoom.y - 1;
			moveHitsWall = false;
		}
		nextRoom.x = currentRoom.x;
		break;
	case ('r'):
		if (currentRoom.y != 'a' + mazeSize - 1) {
			nextRoom.y = currentRoom.y + 1;
			moveHitsWall = false;
		}
		nextRoom.x = currentRoom.x;
		break;
	case ('q'):
		nextRoom = invalidRoom;
		break;
	default:
		cout << "Illegal selection.\n";
		moveHitsWall = false;
		break;
	}
	// print wall hit message
	if (moveHitsWall && !matchRoom(nextRoom, invalidRoom))
		cout << "That's the edge of the maze\n";

	return nextRoom;
}

// note that checkMaze() and matchRoom() are also  used in the game










