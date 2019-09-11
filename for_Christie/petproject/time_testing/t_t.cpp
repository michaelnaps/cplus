#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	time_t start(time(0));
	time_t current(time(0));
	double elapse_time(difftime(current, start));
	
	return 0;
}