// structure definitions and function prototypes maze navigation assignment
// Mikhail Nesterenko 10/21/2022
// Sidney Raabe 10/25 - 10/28/2022

#include <cstdlib>
#include <ctime>


#ifndef MAZE_HPP_
#define MAZE_HPP_

const int mazeSize = 4; // maze is mazeSize * mazeSize
const int numWalls = 8; // number of internal walls

//
// data structures definitions
//

struct Room {
    int x;  // 1 through mazeSize
    char y; // 'a' through mazeSize
};

const Room startRoom = { 1, 'a' };
const Room cheeseRoom = { mazeSize, 'a' + mazeSize - 1 };
const Room invalidRoom = { -1, '*' };

// internal wall or next move
struct RoomPair {
    Room one;
    Room two;
};

//
// initialization functions
//

// sets every passed in room pair within array to -1,*
void clearWalls(RoomPair[]);

//generates a wall between two random rooms
const RoomPair pickWall();

// returns true if the two given rooms are the same
bool matchRoom(const Room&, const Room&);

// returns true if two pairs of adjacent rooms are the same
bool matchPair(const RoomPair&, const RoomPair&);

// returns the the index of a match, or -1 if no match	
int checkMaze(const RoomPair[], const RoomPair);

// places internal walls in random locations of the maze
void build(RoomPair[]);

//
// display functions
//

// prints the location of the room
void printRoom(const Room&);

// prints the locations of a pair of rooms
void printPair(const RoomPair&);

// prints the locations of all the internal walls of the maze
void printMaze(const RoomPair[]);

// prints the maze with nicer UI
// takes in array of walls and mouse location
void printMazeUI(const RoomPair[], Room);

// prints a victory screen
void printWinScreen();
//
// game functions
//

// asks the user an adjacent room to currentRoom to move
const Room nextMove(const Room& currentRoom);

// note that checkMaze() and matchRoom() are also  used in the game

#endif // MAZE_HPP_