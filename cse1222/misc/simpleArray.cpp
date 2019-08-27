#include <iostream>
using namespace std;

int main()
{
	int a[10];
	int i = 0;
	
	cout << "The array made by this program consists of ..." << endl;

	while (i < 10)
	{
		a[i] = (i * 10) + 10;
		cout << a[i] << " ";
		++i;
	}

	cout << endl;
	cout << "The third value is a[2] = " << a[2]
		<< " and the seventh is a[6] = " << a[6] << endl;

	return 0;
}