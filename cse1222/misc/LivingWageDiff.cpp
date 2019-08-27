#include <iostream>
using namespace std;

int main()
{
	double wage;
	double hours;
	double yearlyInc;
	double livingInc = 23381.0;

	cout << "How much do you make per hour? ";
	cin >> wage; 
	cout << endl;

	cout << "How many hours did you work this week? ";
	cin >> hours; 
	cout << endl;

	yearlyInc = wage * hours * 50;

	cout << "You made " << wage * hours << " dollars this week." << endl;

	cout << "By this time next year you will have made " 
		<< yearlyInc << " dollars." << endl;

	if (yearlyInc < livingInc)
	{
		cout << "Based on necessary living wage you are " << livingInc - yearlyInc
			<< " dollars in debt." << endl;
	}

	if (livingInc < yearlyInc)
	{
		cout << "Congratulations! You have a surplus of " << yearlyInc - livingInc 
			<< " dollars." << endl;
	}

	return 0;
}