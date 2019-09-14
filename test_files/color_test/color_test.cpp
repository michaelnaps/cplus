// File: color_test.cpp
// Created by: Michael Napoli

/* Displays the color options included in the windows include file. */

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
	
	for (int i(1); i <= 15; ++i) {
		SetConsoleTextAttribute(hConsole, i);
		cout << "(" << i << ")" << " ";
	}
	
	SetConsoleTextAttribute(hConsole, 7);
	
	return 0;
}