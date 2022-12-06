// defintions for collections tests
// Sidney Raabe
// 11/20/2022

#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

// prints the values of the collection
void Collection::output() const {
	for (int i = 0; i < size_; ++i)
		cout << col_[i] << ", ";
	cout << endl;
}

// returns the sum of the elements in the collection
double Collection::value() const {
	double total = 0;
	for (int i = 0; i < size_; ++i)
		total += col_[i];
	return total;
}

// returns index of element containg "number" or -1 if none
int Collection::check(double number) {
	for (int i = 0; i < size_; ++i)
		if (col_[i] == number)
			return i;
	return -1;
}

// adds number to the collection
void Collection::addNumber(double number) {
	if (check(number) == -1) {
		double* tempColPtr = new double[size_ + 1];
		for (int i = 0; i < size_; ++i)
			tempColPtr[i] = col_[i];
		tempColPtr[size_] = number;

		col_ = new double[++size_];
		for (int i = 0; i < size_; ++i)
			col_[i] = tempColPtr[i];

		delete[] tempColPtr;
	}
}

// deletes the number from the collection
void Collection::removeNumber(double number) {
	// match at last index
	if (check(number) == size_ - 1 && size_ > 0) { 
		double* tempColPtr = new double[size_ - 1];
		// copy left of matching index
		for (int i = 0; i < size_ - 1; ++i)
			tempColPtr[i] = col_[i];
		col_ = new double[--size_];
		for (int i = 0; i < size_; ++i)
			col_[i] = tempColPtr[i];
		delete[] tempColPtr;
	}
	// match at any other index
	else if (check(number) != -1) {
		double* tempColPtr = new double[size_ - 1];
		for (int i = 0; i < size_; ++i) {
			if (col_[i] == number) {
				// copy left of i
				for (int j = 0; j < i + 1; ++j)
					tempColPtr[j] = col_[j];
				// copy right of i
				for (int j = i; j < size_ - 1; ++j)
					tempColPtr[j] = col_[j + 1];
				break;
			}
		}
		col_ = new double[--size_];
		for (int i = 0; i < size_; ++i)
			col_[i] = tempColPtr[i];
		delete[] tempColPtr;
	}
	// not in array
	else;

}


// destructor
Collection::~Collection() {
	delete[] col_;
}
// copy
Collection::Collection(const Collection& original) {
	size_ = original.size_;
	col_ = new double[size_];
	for (int i = 0; i < size_; ++i)
		col_[i] = original.col_[i];
}
// overload assignment
Collection& Collection::operator=(const Collection& original) {
	if (this != &original) {
		size_ = original.size_;
		delete[] col_;
		col_ = new double[size_];
		for (int i = 0; i < size_; ++i)
			col_[i] = original.col_[i];
	}
	return *this;
}

