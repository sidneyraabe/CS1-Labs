// defintions for collections tests
// Sidney Raabe
// 11/8/2022

#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

//prints the values in array "colPtr" of "size" 
//takes the pointer to the array and its size and prints the array's content
void output(const double* colPtr, const int size) {
	for (int i = 0; i < size; ++i)
		cout << colPtr[i] << ", ";
	cout << endl;
}

// returns the sum of all the values in array "colPtr" of "size"
//takes the pointer to the arrayand its sizeand returns the total value of all the numbers in the array
double value(const double* colPtr, const int size) {
	double total = 0;
	for (int i = 0; i < size; ++i)
		total += colPtr[i];
	return total;
}

//takes the pointer to the array and a number and checks if the number is in the array. 
//If the number is in the array, returns the index of the element of the array holding the number. 
//Otherwise, returns -1
int check(const double* colPtr, const double number, const int size) {
	for (int i = 0; i < size; ++i)
		if (colPtr[i] == number)
			return i;
	return -1;
}

// adds "number" to the array pointed to by "colPtr" of "size". 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased. 
void addNumber(double*& colPtr, const double number, int& size) {
	if (check(colPtr, number, size) == -1) {
		double* tempColPtr = new double[size + 1];
		for (int i = 0; i < size; ++i)
			tempColPtr[i] = colPtr[i];
		tempColPtr[size] = number;

		colPtr = new double[++size];
		for (int i = 0; i < size; ++i)
			colPtr[i] = tempColPtr[i];

		delete[] tempColPtr;
	}
}

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double*& colPtr, const double number, int& size) {
	// match at last index
	if (check(colPtr, number, size) == size - 1) {
		double* tempColPtr = new double[size - 1];
		// copy left of matching index
		for (int i = 0; i < size - 1; ++i)
			tempColPtr[i] = colPtr[i];
		colPtr = new double[--size];
		for (int i = 0; i < size; ++i)
			colPtr[i] = tempColPtr[i];
		delete[] tempColPtr;
	}
	// match at any other index
	else if (check(colPtr, number, size) != -1) {
		double* tempColPtr = new double[size - 1];
		for (int i = 0; i < size; ++i) {
			if (colPtr[i] == number) {
				// copy left of i
				for (int j = 0; j < i + 1; ++j)
					tempColPtr[j] = colPtr[j];
				// copy right of i
				for (int j = i; j < size - 1; ++j)
					tempColPtr[j] = colPtr[j + 1];
				break;
			}
		}
		colPtr = new double[--size];
		for (int i = 0; i < size; ++i)
			colPtr[i] = tempColPtr[i];
		delete[] tempColPtr;
	}
	// not in array
	else;
		
}
