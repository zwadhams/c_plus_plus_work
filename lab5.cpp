#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
using namespace std;

void error(string s) { //function to assist errors
    throw runtime_error("Error: " + s);
}

vector<string> buildVector(int num) { //builds the vector
    vector<string> v1 = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> v2 = {"", "no", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    vector<string> v3 = {"", "", "", "hundred", "thousand"};

    vector<string> words; //vector to be returned

    int num_digits = (int)log10(double(num)) + 1; //gets the number of digits
   
    for (int i = 1; i <= num_digits; ++i) { //loops through input
        int digit = num % 10;
        num /= 10;
        
        if (i != 2) {
            words.push_back(v3[i]);
            words.push_back(v1[digit]);
        }

        else {
            words.push_back(v2[digit]);
        } 
    } 
    return words;
}

int main(int argc, char** argv) {
       

    if (argc != 2) { //if no number is given
        error("Number not on command line. exiting run");
    }

    if (argv[1][1] == '1') { //if second digit is one
        error("Second digit cannot be 1. exiting run");
    } 
    
    int userInput = atoi(argv[1]);    
    
    vector<string> myVector = buildVector(userInput);
    cout << "Number " << userInput << " is written as ";

    while (!myVector.empty()) { //loops through vector to print out 
        cout << myVector.back() << " ";
        myVector.pop_back();
    }    

    return 0;
}
