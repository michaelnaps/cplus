// extract to string
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string name;
	const double pi = 3.1415926535897932384626433832795;

	cout << "Please, enter your full name: ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";

	cout << endl << pi << endl;

	return 0;
}