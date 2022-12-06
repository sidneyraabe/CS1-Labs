// mouse 2d array, display trail of moves
// cardinal directions implemented, no checks for borders
// Sidney Raabe
// 12-5-2022

#include <iostream>
using std::cin; using std::cout; using std::endl;

// maze dimensions
const int mazeLength = 6;
const int mazeWidth = 6;
void initializeArray(bool [mazeLength][mazeWidth]);
void displayMaze(bool[mazeLength][mazeWidth]);
int main() {

	int mouseX = 0; // current mouse X index
	int mouseY = 0; // current mouse Y index
	bool maze[mazeLength][mazeWidth]; // declare mouse maze tracking array
	initializeArray(maze);	
	maze[mouseX][mouseY] = true;
	bool quit = false;
	char userInput;
	do {
		system("CLS");
		displayMaze(maze);
		cout << endl << "(l)eft, (r)ight, (u)p, (d)own or (q)uit: ";
		cin >> userInput;
		switch (userInput) {
		case 'u':
			mouseX--;
			break;
		case 'd':
			mouseX++;
			break;
		case 'l':
			mouseY--;
			break;
		case 'r':
			mouseY++;
			break;
		case 'q':
			quit = true;
			break;
		default:
			cout << "Invalid selection." << endl;
			break;
		}
		maze[mouseX][mouseY] = true;
	} while (!quit);
}
void displayMaze(bool maze[mazeLength][mazeWidth]) {
	//header row
	cout << " ";
	for (int i = 0; i < mazeWidth; ++i)
		cout << " " << static_cast<char>(i + 'a');
	//data rows
	for (int row = 0; row < mazeLength; ++row) {
		cout << endl;
		cout << row + 1 << " ";
		for (int col = 0; col < mazeWidth; ++col) {
			if (maze[row][col]) {
				cout << "* ";
				continue;
			}
			cout << "  ";
		}
	}
}
void initializeArray(bool maze[mazeLength][mazeWidth]) {
	for (int i = 0; i < mazeLength; ++i) {
		for (int j = 0; j < mazeWidth; ++j)
			maze[i][j] = false;
	}
}