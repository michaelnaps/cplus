// Lecture 19
// topics include: File I/O Streams
/*
notes:
	-a stream is a permanent input or output that cannot be changed after submission
	-streams are evaluated in a LINEAR order
	-Write to a file:
		1. Use #include <fstream>
		2. Create an output stream object
		3. Establish connection to file
		4. Check validity
	   5. WRITE
		6. Close the file
	#include <fstream>
		-introduces output file stream commands
	-"Check validity"
		-use if statement that includes command
		variableName.is_open()
	-write to file as you would usually use the 'cout' command
		variableName << output;
	-the following command converts string variables to c++ style strings
		variableName.c_str()
	-this is useful when writing to other files AND interacting with other people's code

	-Read From a File:
		varaible type: ifstream variableName;
		-use following command to loop through open-to-read files
		variableName.fail()
		-this command becomes TRUE when the file FAILS
		-while loop example
			while (!variableName.fail()) { }
		-the variable name itself is also equivalent to the aforementioned boolean
			while (variableName) { }
			-is ultimately the same
		variableName.eof() - returns true when the end of the file being read is reached
		
		IMPORTANT:
		-when passing an output/input file to a function, it MUST be by reference and NOT constant
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string userInput, file_name;
	ofstream fout;  // create output file variable
	ifstream fin;  // read in a file
	string file_content;

	cout << "What is the file name? ";
	getline(cin, file_name);

	fout.open(file_name, ios::out);  // opens and connects variable to file

	// checks if file is opened successfully
	if (!fout.is_open()) {
		cerr << "Unable to open file " << file_name << endl;
		return 10;
	}

	cout << "Enter text: ";
	getline(cin, userInput);

	fout << userInput;  // writes to designated files

	fout.close();  // closes file that was previously opened

	// READ IN FILE

	cout << "What file do you want to read from? ";
	getline(cin, file_name);

	fin.open(file_name, ios::in);  // open file to be read from

	if (!fin.is_open()) {
		cerr << "Unable to open file " << file_name << endl;
		return 10;
	}

	getline(fin, file_content);  // read from the opened file

	cout << file_content << endl;

	fin.close();  // close output file

	return 0;
}