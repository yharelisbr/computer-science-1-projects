/* CISC1600
 * Lab 7: Sin Print or Graph
 *
 * Yharelis Ribic
 * Last edited: October 31, 2023
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

//Precondition: the input degrees should be a valid angle values.
//Postcondition: converts degrees to radians and returns the result.

double DegreesToRadians(double degrees) {
    return degrees * (PI / 180.0);
}


//Precondition:The input character should be a valid ASCII character, and numRepetitions should be a non-negative integer.
//Postcondition: Prints the input character repeated numRepetitions times followed by a newline.

void DrawLine(char character, int numRepetitions) {
    for (int i = 0; i < numRepetitions; ++i) {
        cout << character;
    }
    cout << endl;
}


//Precondition: maxAngle and angleIncrement should be non-negative integers.
//characterToPrint should be a valid ASCII character, and numberOfCharsToPrint should be a positive integer.
//Postcondition: Prints the sine values for angles from 0 to maxAngle with the specified angle increment.
//If angle is a multiple of 90, prints a line of characters based on the sine value.

void doPrinting(int maxAngle, int angleIncrement, char characterToPrint, int numberOfCharsToPrint) {
    	int numCharsInLine = numberOfCharsToPrint;
	for (int angle = 0; angle <= maxAngle; angle += angleIncrement) {
        double sinVal = sin(DegreesToRadians(angle));
        cout << fixed << setprecision(5) << "sin(" << angle << ") = " << sinVal << endl;
        
        if (angle % 90 == 0) {
            int spaces = static_cast<int>(sinVal * numCharsInLine);
        if(spaces >=0) {
		spaces += numCharsInLine;
	}else {
		spaces -= numCharsInLine;
	}
	    DrawLine(characterToPrint,numCharsInLine);
        }
    }
}
//Precondition: maxAngle and angleIncrement should be non-negative integers.
//characterToPrint should be a valid ASCII character, and numberOfCharsToPrint should be a positive integer.
//Postcondition: Prints a graph of the sine function from 0 to maxAngle with the specified angle increment

void doGraphing(int maxAngle, int angleIncrement, char characterToPrint, int numberOfCharsToPrint) {
    for (int angle = 0; angle <= maxAngle; angle += angleIncrement) {
        double sinVal = sin(DegreesToRadians(angle));
        int spaces = static_cast<int>(sinVal * numberOfCharsToPrint + numberOfCharsToPrint);
        for (int i = 0; i < spaces; ++i) {
            cout << " ";
        }
        cout << "X" << endl;
    }
}

int main() {
    int maxAngle, angleIncrement;
    char graph;

//Precondition: The user provides valid input for maxAngle, angleIncrement, and graph (character 'Y' or 'N').
//Postcondition: Reads user input for maxAngle, angleIncrement, and graph from the standard input.

    cout << "Perform calculations from angle=0 to what value (in degrees)? ";
    cin >> maxAngle;
    cout << "How often should the angle be incremented? ";
    cin >> angleIncrement;
    cout << "Graph it? ";
    cin >> graph;
    
    if (graph == 'Y' || graph == 'y') {
        doGraphing(maxAngle, angleIncrement, 'X', 20);
    } else {
        char lineCharacter;
 	int numCharsInLine;
        
        cout << "Make the line from what character? ";
        cin >> lineCharacter;
        cout << "How many characters form a line? ";
        cin >> numCharsInLine;

//Precondition: maxAngle, angleIncrement, and numberOfCharsToPrint are non-negative integers.
//characterToPrint is a valid ASCII character.
//Postcondition: Calls doPrinting function to print a pattern of characters based on the sine function and user input.       
  
  	doPrinting(maxAngle, angleIncrement, lineCharacter, numCharsInLine);
    }

    return 0;
}

