// File: tweetDecoder.cpp
// Created by: Michael Napoli
// Created on: 5-25-2019
// Last modified: 5-25-2019

/* Program that evaluates commonly used abreviations 
	and outputs their meaning. */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string origTweet;
	string newAbrev;
	string empty;

	cout << "Enter abbreviation from tweet: ";
	cin >> origTweet;

	if (origTweet == "LOL") {
		cout << "LOL = laughing out loud" << endl;
	}
	else if (origTweet == "BFN") {
		cout << "BFN = bye for now" << endl;
	}
	else if (origTweet == "FTW") {
		cout << "FTW = for the win" << endl;
	}
	else if (origTweet == "IRL") {
		cout << "IRL = in real life" << endl;
	}
	else if (origTweet == "BTW") {
		cout << "BTW = by the way" << endl;
	}
	else {
		cout << "Sorry, don't know that one, but I would like to learn!" << endl;
		cout << "What does it mean? ";
		getline(cin, empty);
		getline(cin, newAbrev);
		cout << "Thanks for teaching me! Now I know that..." << endl;
		cout << origTweet << " = " << newAbrev << endl;
	}

	return 0;
}