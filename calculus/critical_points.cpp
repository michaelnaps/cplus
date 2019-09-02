#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{	
	vector<double> x_list;
	vector<double> y_list;
	
	for (double i(1); i < 100; ++i) {
		for (double k(1); k < 100; ++k) {
			if (4 * i + 2 * k == 102) {
				cout << i << " " << k << " " << i * k << endl;
				x_list.push_back(i);
				y_list.push_back(k);
			}
		}
	}
	cout << endl;
	for (double i(1); i < 100; ++i) {
		for (double k(1); k < 100; ++k) {
			if (4 * k + 2 * i == 102) {
				cout << i << " " << k << " " << i * k << endl;
				x_list.push_back(i);
				y_list.push_back(k);
			}
		}
	}
	
	return 0;
}