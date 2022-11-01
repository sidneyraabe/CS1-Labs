// Lab7_LineJustify.cpp : This file justifies user-given lines
// Sidney Raabe
// 10/20/2022

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

void justify(string& input);
const int lineLength = 80;
int main()
{
	string inputLine;
	cout << "Input line: " << endl;
	std::getline(cin, inputLine);
	cout << "Your line justified: " << endl;
	justify(inputLine);
	cout << inputLine;
}

void justify(string& input) {
	int i = 0;
	int size = input.length();
	srand(time(nullptr));

	//add single space after punctuation
	int pos = input.find(",.!?:");
	while (pos != string::npos) { input.insert(pos + 1, 1, ' '); }

	size = input.length();
	i = 0;

	//add spaces until 80 chars long
	while (true) {
		if (size >= lineLength) //end loop
			break;
		if (input[i] == ' ')

			//if 50% chance, randomly add space
			if (rand() % 2 == 0) {
				input.insert(i + 1, 1, ' ');
				size++;

			}
		i++;
		//loop again if reach end and size < 80
		if (i >= size)
			i = 0;
	}
}

