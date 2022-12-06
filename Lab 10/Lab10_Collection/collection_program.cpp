// flow for user-submitted numbers
// implements functions from testcollection
// Sidney Raabe
// 11/08/2022

#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
	char selection;
	double userNumber, total;
	bool hasQuit = false;
	int size = 0;
	double* collection = new double[0];
	do {
		// reset total;
		total = 0;
		//prompt user for input
		cout << "Enter operation [a/r/q] and number: ";
		cin >> selection >> userNumber;

		// lowercase selection because I'm nice
		selection = tolower(selection);
		switch (selection) {
		case 'a':
			// add number
			if (check(collection, userNumber, size) != -1) {
				cout << "Number exists in array." << endl;
			}
			addNumber(collection, userNumber, size);
			break;
		case 'r':
			// remove number
			if (check(collection, userNumber, size) == -1)
				cout << "Number does not exist in array." << endl;
			removeNumber(collection, userNumber, size);
			break;
		case 'q':
			//quit
			hasQuit = true;
			break;
		default:
			// bad input
			break;
		}
		// check size so nothing shows on empty array
		if (!hasQuit && size > 0) {
			output(collection, size);
			for (int i = 0; i < size; ++i)
				total += collection[i];
			cout << "Total: " << total << endl;
		}
		
	} while (!hasQuit);
	return 0;
}