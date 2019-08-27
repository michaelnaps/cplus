// File: outputFile.cpp
// Created by: Michael Napoli
// Created on: 7/8/2019
// Last modified on: 

/* Function that takes string of the input file name and
	gives an ouput file name to be written to in the main 
	program. */

#include <iostream>
#include <string>
using namespace std;

// FUNCTION PROTOTYPE: outputFile()
string outputFile(string inputFile);

int main{
	string inputName("inData.txt");

	outputName = outputFile(inputName);

	return 0;
}

// FUNCTION DEFINITION: outputFile()
string outputFile(string inputFile)
{
	if (inputFile.substr(0, 2) == "in") {  // if intial file name starts with "in"
		inputFile.replace(0, 2, "out");  // output file name will start with "out" instead
	}
	else {  // otherwise place "out." at the beginning of the name
		inputFile.insert(0, "out.");
	}

	return inputFile;
}