#include <iostream>
using namespace std;

int main()
{
	int sum;
	int exp_;

	cout << "What is your starting value? ";
	cin >> sum;

	while (sum < 100)
	{
		sum = sum + sum;
		exp_ = sum * sum;
	}

	cout << sum << "   " << exp_ << endl;

	return 0;
}
