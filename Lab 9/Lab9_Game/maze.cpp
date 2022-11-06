// class definitions for maze navigation assingment
// Mikhail Nesterenko 10/28/2022
// Sidney Raabe 11/05/2022

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

/*
++++++++++++++++++++++++
	 ROOM FUNCTIONS
++++++++++++++++++++++++
*/

// selects a random room within the maze
void Room::pick() { x_ = rand() % mazeSize_ + 1; y_ = rand() % mazeSize_ + 'a'; }

// selects a random valid adjacent room
const Room Room::pickAdjacent() {
	int randomNum;
	char decision = ' ';
	do {
		randomNum = rand() % 4;
		switch (randomNum) {
		case 0:
			decision = 'u'; break;
		case 1:
			decision = 'd'; break;
		case 2:
			decision = 'l'; break;
		default:
			decision = 'r'; break;
		}
	} while ((!goodDirection(decision)));
	return createAdjacent(decision);
}

// asks the user for the room to move adjacent to this room, {-1,*} if quit
const Room Room::nextMove() const {
	char input;
	cin >> input;
	input = tolower(input);

	if (input == 'q')
		return Room();

	Room current;
	current.x_ = x_;
	current.y_ = y_;

	if (goodDirection(input))
		return createAdjacent(input);
	else
		return current;
}

// prints room coordinates in format "a1"
void Room::print() const { std::cout << x_ << y_; }

// predicate returns true if the coordinates of the two rooms match
bool matchRoom(const Room& room1, const Room& room2) {
	return room1.x_ == room2.x_ && room1.y_ == room2.y_;
}

//returns true if the given input direction character points to a valid room
bool Room::goodDirection(const char input) const {
	bool output = false;
	switch (input) {
	case ('u'):
		if (x_ != 1) output = true; break;
	case ('d'):
		if (x_ != mazeSize_) output = true; break;
	case ('l'):
		if (y_ != 'a') output = true; break;
	case ('r'):
		if (y_ != mazeSize_ - 1 + 'a') output = true; break;
	}
	return output;
};

// returns the room adjacent to this room in the specified direction
const Room Room::createAdjacent(const char input) const {
	Room newRoom;
	switch (input) {
	case ('u'):
		newRoom.x_ = x_ - 1; newRoom.y_ = y_; break;
	case ('d'):
		newRoom.x_ = x_ + 1; newRoom.y_ = y_; break;
	case ('l'):
		newRoom.y_ = y_ - 1; newRoom.x_ = x_; break;
	case ('r'):
		newRoom.y_ = y_ + 1; newRoom.x_ = x_; break;
	}
	return newRoom;
}

/*
++++++++++++++++++++++++
   ROOMPAIR FUNCTIONS
++++++++++++++++++++++++
*/

//selects a random wall, uses Room::pickAdjacent()
void RoomPair::pick() {
	Room firstRoom;
	firstRoom.pick();
	one_ = firstRoom;
	Room adjacentRoom = firstRoom.pickAdjacent();
	two_ = adjacentRoom;
}

// prints the locations of the adjacent rooms
void RoomPair::print() const { one_.print();  two_.print(); }

// returns true if two pairs of adjacent rooms are the same
bool matchPair(const RoomPair& pairOne, const RoomPair& pairTwo) {
	return (matchRoom(pairOne.one_, pairTwo.one_) && matchRoom(pairOne.two_, pairTwo.two_)
		|| matchRoom(pairOne.one_, pairTwo.two_) && matchRoom(pairOne.two_, pairTwo.one_));
}

/*
++++++++++++++++++++++++
	 MAZE FUNCTIONS
++++++++++++++++++++++++
*/

// prints the locations of all the internal walls of the maze and current location
void Maze::print() const {
	for (int i = 0; i < numWalls_; ++i) {
		maze_[i].print(); cout << ", ";
	}
	cout << endl; cout << "Mouse location: "; currentRoom_.print(); cout << endl;
}

// places internal walls in random unique locations of the maze
void Maze::build() {
	RoomPair temp;
	bool isNew;
	for (int i = 0; i < numWalls_; ++i) {
		isNew = true;
		temp.pick();
		//check if wall pair exists
		for (int j = 0; j < i; ++j) {
			if (matchPair(temp, maze_[j]))
			{
				isNew = false;
				--i;
				break;
			}
		}
		//only add wall if passes check
		if (isNew)
			maze_[i] = temp;
	}
}

// moves mouse and returns true, returns false if not
bool Maze::move(const Room& newMoveRoom) {
	RoomPair rp(currentRoom_, newMoveRoom);
	if (checkMaze(rp) != -1)
		return false;

	// invalid input handling
	if (matchRoom(currentRoom_, newMoveRoom))
		return false;

	currentRoom_ = newMoveRoom;
	return true;
}

// returns the index of the element in maze_ that separates RoomPair (your move), or -1
int Maze::checkMaze(const RoomPair& currentMove) const {
	for (int i = 0; i < numWalls_; ++i) {
		if (matchPair(currentMove, maze_[i])) {
			cout << "...That's a wall: "; maze_[i].print(); cout << endl;
			return i;
		}
	}
	return -1;
};


