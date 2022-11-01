// Lab7_TextJustify.cpp : Justifies each line of a file
// Sidney Raabe
// 10/20/2022

#include <fstream>
#include <iostream>
#include <string>

using std::ifstream; using std::ofstream;
using std::cout; using std::cin; using std::endl;
using std::string;

void justifyLine(string& input);
const int lineLength = 80;

int main()
{
	string fileName = "unjustified.txt";
	ifstream fin(fileName);
	string line;

	string outputFileName = "justified.txt";
	ofstream fout(outputFileName);

	while (getline(fin, line)) {
		if (line.length() > 40)
			justifyLine(line);
		fout << line << endl;
	}

	fin.close();
	fout.close();
}

void justifyLine(string& input) {
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