// File: forLoopEx.cpp
// Created by: Michael Napoli
// Created on: 5/26/2019

#include <iostream>
using namespace std;

int main()
{
	int i;
	double getBig;

	cout << "How BIG you wanna get? ";
	cin >> getBig;

	for (i = 1; i < getBig; ++i)
	{
		cout << i << " ";
		if (i % 10 == 0)
		{
			cout << endl;
		}
	}

	cout << getBig << endl;
	cout << "You made it!" << endl;

	return 0;
}