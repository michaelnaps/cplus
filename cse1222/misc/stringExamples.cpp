#include <iostream>
#include <string>
using namespace std;

/* Program that displays the different 
	verions of string variables. */

int main()
{
	char a; // for single letter/symbols
	string b; // for whole words
	string hide; //steals the enter from b
	string name; // uses getline command later

	cout << "Enter a single letter for char variable: ";
	cin >> a;
	cout << "a = " << a << endl;

	cout << endl << "Enter a single word for string variable: ";
	cin >> b;
	cout << "b = " << b << endl << endl;

	getline(cin, hide); // uses the newline symbol from the previous cin command

	cout << "Word variable properties with whitespace require the getline() command..." << endl;
	cout << "Please, enter your full name: ";
	getline(cin, name);
	cout << "Hello, " << name << "!" << endl;

	return 0;
}