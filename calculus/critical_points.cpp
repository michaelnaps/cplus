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
			if (((102 * k) - (4 * i * k) - (2 * k * k)) == 0) { 
				x_list.push_back(i);
				y_list.push_back(k);
			}
		}
	}
	
	return 0;
}