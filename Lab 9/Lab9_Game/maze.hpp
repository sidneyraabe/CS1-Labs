// class definitions for maze navigation assingment
// Mikhail Nesterenko
// 10/28/2022

#include <cstdlib>
#include <ctime>

#ifndef MAZE_HPP_
#define MAZE_HPP_

class Room {
public:
    // void constructor, assigns -1 to X coord, and * to Y coord
    Room() : x_(-1), y_('*') {};

    // selects a random room within the maze
    void pick();

    // selects a random adjacent room
    const Room pickAdjacent();

    // asks the user for the room to move adjacent to this room, {-1,*} if quit
    const Room nextMove() const;

    // prints room coordinates in format "a1"
    void print() const;

    // make this room the start room
    void makeStartRoom() { x_ = 1, y_ = 'a'; }

    // make this room - the cheese room
    void makeCheeseRoom() { x_ = mazeSize_, y_ = 'a' + mazeSize_ - 1; }

    // predicate returns true if the coordinates of the two rooms match
    friend bool matchRoom(const Room&, const Room&);

private:
    // checks if this direction keeps the mouse inside the maze
    bool goodDirection(const char input) const;

    // returns the room adjacent to this room in the specified direction
    const Room createAdjacent(const char input) const;

    // maze is mazeSize * mazeSize
    static const int mazeSize_ = 4;

    // 1 through mazeSize
    int x_;

    // 'a' through mazeSize
    char y_;
};




// internal wall or next move
class RoomPair {
public:
    // void constructor implicitly invokes void constructors on member variables
    RoomPair() : one_(Room()), two_(Room()) {}

    // makes a roomPair out of two rooms
    RoomPair(const Room& one, const Room& two) :one_(one), two_(two) {}

    //selects a random wall
    void pick(); 

    // prints the locations of the adjacent rooms
    void print() const; 

    // returns true if two pairs of adjacent rooms are the same,
    friend bool matchPair(const RoomPair&, const RoomPair&);

private:
    Room one_;
    Room two_;
};




class Maze {
public:
    // creates empty wall RoomPair array
    Maze() {};

    // prints the locations of all the internal walls of the maze and current location
    void print() const;

    // places internal walls in random unique locations of the maze
    void build();

    // places current mouse location in startRoom_;
    void start() { currentRoom_.makeStartRoom(); }

    // moves mouse and returns true, returns false if not
    bool move(const Room&);

    // returns current mouse location
    const Room getCurrentRoom() { return currentRoom_; }

private:
    // returns the index of the element in maze_ that separates RoomPair (your move), or -1
    int checkMaze(const RoomPair&) const;

    // current mouse Location
    Room currentRoom_;

    // number of internal walls
    static const int numWalls_ = 8;

    // number of internal walls
    RoomPair maze_[numWalls_];
};

#endif // MAZE_HPP_