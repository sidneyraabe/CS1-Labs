// same collection program as before but with vectors
// Sidney Raabe
// 12-4-2022

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

vector<float>::iterator returnMatch(vector<float>&, float);
bool addInputIsSuccess(vector<float>&, float);
bool removeInputIsSuccess(vector<float>&, float);
void displayNumbers(vector<float>&);

int main()
{
    vector<float> userVector; char inputOperation; float inputNumber;
    bool quit = false; 
    do {
        cout << "Enter operation [a/r/q] and number: ";
        cin >> inputOperation >> inputNumber;

        switch (inputOperation) {
        case 'a':
            if (!addInputIsSuccess(userVector, inputNumber))
                cout << "Number is duplicate." << endl;
            break;
        case 'r':
            if (!removeInputIsSuccess(userVector, inputNumber))
                cout << "Number not found." << endl;
            break;
        case 'q':
            quit = true;
            break;
        default:
            cout << "Invalid selection." << endl;
            break;
        }
        if (!quit) displayNumbers(userVector);
            
    } while (!quit);
}

bool addInputIsSuccess(vector<float> &vec, float inputNumber) {
    vector<float>::iterator it = returnMatch(vec, inputNumber);
    if (it == vec.end()) {
        vec.push_back(inputNumber);
        return true;
    }
    return false;
}

bool removeInputIsSuccess(vector<float>& vec, float inputNumber) {
    vector<float>::iterator it = returnMatch(vec, inputNumber);
    if (it != vec.end()) {    
        vec.erase(it);
        return true;
    }
    return false;
}

void displayNumbers(vector<float>& vec) {
    cout << "Your numbers: ";
    for (auto ip = vec.begin(); ip != vec.end(); ++ip)
        cout << *ip << " ";
    cout << endl;
}

vector<float>::iterator returnMatch(vector<float>& vec, float inputNumber) { 
    return find(vec.begin(), vec.end(), inputNumber); 
}