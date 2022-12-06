// flow for user-submitted numbers, DYNAMIC EDITION
// Sidney Raabe
// 11/28/2022

#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
	char selection;
	double userNumber;
	bool hasQuit = false;
	Collection myObj;
	do {
		//prompt user for input
		cout << "Enter operation [a/r/q] and number: ";
		cin >> selection >> userNumber;

		// lowercase selection because I'm nice
		selection = tolower(selection);

		switch (selection) {
		case 'a':
			// add number
			if (myObj.check(userNumber) != -1)
				cout << "Number exists in array." << endl;
			myObj.addNumber(userNumber);
			break;
		case 'r':
			// remove number
			if (myObj.check(userNumber) == -1)
				cout << "Number does not exist in array." << endl;
			myObj.removeNumber(userNumber);
			break;
		case 'q':
			//quit
			hasQuit = true;
			break;
		default: break; //bad input
		}
		myObj.output();
		cout << myObj.value() << endl;
	} while (!hasQuit);
	return 0;
}