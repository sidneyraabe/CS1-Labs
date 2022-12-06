// functions to manipulate collection
// Mikhail Nesterenko
// 11/7/2022

#ifndef COLLECTION_HPP
#define COLLECTION_HPP

//prints the values in array "colPtr" of "size" 
//takes the pointer to the array and its size and prints the array's content
void output(const double* colPtr, const int size);

// returns the sum of all the values in array "colPtr" of "size"
//takes the pointer to the arrayand its sizeand returns the total value of all the numbers in the array
double value(const double* colPtr, const int size);

//takes the pointer to the array and a number and checks if the number is in the array. 
//If the number is in the array, returns the index of the element of the array holding the number. 
//Otherwise, returns -1
int check(const double* colPtr, const double number, const int size);

// adds "number" to the array pointed to by "colPtr" of "size". 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased. 
void addNumber(double*& colPtr, const double number, int& size);

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double*& colPtr, const double number, int& size);

#endif // COLLECTION_HPP