// class definitions for maze navigation assingment
// Mikhail Nesterenko
// 10/28/2022

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

Room::Room() {
	x_ = -1;
	y_ = '*';
}

const Room Room::createAdjacent(const char input) const {
	Room newRoom;
	switch (input) {
	case ('u'):
		newRoom.x_ = x_ - 1;
		newRoom.y_ = y_;
		break;
	case ('d'):
		newRoom.x_ = x_ + 1;
		newRoom.y_ = y_;
		break;
	case ('l'):
		newRoom.y_ = y_ - 1;
		newRoom.x_ = x_;
		break;
	case ('r'):
		newRoom.y_ = y_ + 1;
		newRoom.x_ = x_;
		break;
	}
	return newRoom;
}

bool Room::goodDirection(const char input) const {
	bool output = false;
	switch (input) {
	case ('u'):
		if (x_ != 1)
			output = true;
		break;
	case ('d'):
		if (x_ != mazeSize_)
			output = true;
		break;
	case ('l'):
		if (y_ != 'a')
			output = true;
		break;
	case ('r'):
		if (y_ != mazeSize_ - 1) {
			output = true;
		}
		break;
	}
	return output;
};
// selects a random room within the maze
void Room::pick() {
	x_ = rand() % mazeSize_ + 1;
	y_ = rand() % mazeSize_ + 'a';
}
bool matchRoom(const Room& room1, const Room& room2) {
	return room1.x_ == room2.x_ &&
		room1.y_ == room2.y_;
}
// selects a random adjacent room
// uses goodDirection() and createAdjacent()
//const Room Room::pickAdjacent() {
//}

	// asks the user for the room to move adjacent to this room
	// returns {-1,*} if the user wants to quit
	// uses goodDirection() and createAdjacent()
const Room Room::nextMove() const {
	char input;
	cin >> input;
	if (input == 'q')
		return Room();

	Room current;
	current.x_ = x_;
	current.y_ = y_;

	if (goodDirection(input))
		return createAdjacent(input);
	else {
		// bad selection
		return current;
	}
}

void Room::print() const {
	cout << x_ << y_;
}   // prints room coordinates in format "a1"
	// void constructor implicitly invokes void constructors on member variables

// makes a roomPair out of two rooms
//RoomPair::RoomPair(const Room& one, const Room& two) :one_(one), two_(two) {};

//void RoomPair::pick() {}; //selects a random wall, uses Room::pickAdjacent()

void RoomPair::print() const {
	one_.print();  two_.print();
}; // prints the locations of the adjacent rooms

// returns true if two pairs of adjacent rooms are the same,
// returns false otherwise, uses matchRoom() note that r1|r2 matches r2|r1
//bool matchPair(const RoomPair&, const RoomPair&);


/*
class Maze {
public:
	Maze() {} // places every wall between two rooms where x-coordinate is -1
			  // and y-coordinate is '*' (a star) to signify that
			  // the wall is not built yet

	// prints the locations of all the internal walls of the maze
	// and current mouse location
	void print() const;

	// places internal walls in random locations of the maze
	// all walls are different
	void build();

	// places current mouse location in startRoom_;
	void start() { currentRoom_.makeStartRoom(); }

	// takes the room to move the mouse to
	// moves the mouse there and returns true if no walls (move is possible)
	// does not move the mouse and returns false if wall
	bool move(const Room&);

	// returns current mouse location
	const Room getCurrentRoom() { return currentRoom_; }

private:
	// returns the index of the element in maze_ that separates RoomPair
	// returns -1 if none do, uses matchPair()
	int checkMaze(const RoomPair&) const;

	Room currentRoom_; // current mouse Location

	static const int numWalls_ = 8;  // number of internal walls
	RoomPair maze_[numWalls_]; // number of internal walls
};
*/
