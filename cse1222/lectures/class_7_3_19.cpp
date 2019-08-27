// Lecture 15
// topics include: Midterm II topics, pointers, dynamic memory, arrays and pointers
/*
notes:
	-Midterm II:
		-over labs 1-8
		-important commands:
			#include <iostream> <cmath> <iomanip>
			cout.precision(x) cout.setf(ios::fixed) cout.setf(ios::scientific)
			swap()
		-topics:
			fixed, scientific, setprecision, setw
			for and while loops
			functions (prototype and definition)
			pass by value vs. pass by reference
			scope of functions
			arrays
			passing arrays to a function
			constant arrays

	-Lecture:
		-pointer operator: (* and &)
			*pointerName = &variableName;
		-"pointerName points to varaibleName"
		-variables types of pointers and their variable must be the same
		-Dereference operator:
			cout << *pointerName;
			-displays whatever is in the pointer address
		-pointer addresses can always be changed
		-pointers can replace "pass by reference" variables within functions
			-needed for C programming, not C++
		-main use for pointers: dynamic memory
		-fixed memory allocation:	(known before program is compiled)
			int num; or int arr[5];
		-dynamic memory allocation:	(only known once program is run)
			int* num = new int;
			int* arr = new int[10];	// array size does not need to be known at compile time
		-when pointers are used, variable at addresses do NOT have a name
		-the 'new' command finds an open memory space and reserves it
		-problem: memory slot used via 'new' never goes away on its own
		-answer: use command 'delete' to erase the memory allocation space
			-only delete things allocated using 'new' command
		-Dangling pointer - pointer variable that points to something that no
			longer exists
			-just because something should no longer exist, does not mean its gone
			-especially hard to debug
		-to avoid a dangling pointer, the unused pointer is set to 0, or nullptr
		-to do this:
			delete pointerName;		// deletes the number the pointer points to
			pointerName = nullptr;	// sets it to point at null space and will crash if attempted to access
		-array varaibles are actually pointers
		-the varaible name for an array is actually a pointer to the first 
			value of the array
		-dynamic allocation can be used to change the size of an array
			arr = new int[x]
			arr = new int [y]	// changes array size to y instead of x
		-it is still important to delete and size arrays appropriately
			delete [] arrayName;
		-memory leak:
			-program allocated memory but never deleted the pointed to value
			-once the variable name goes away, the memory space is inaccessible...
*/

#include <iostream>
using namespace std;

int main()
{
	int num = 32;
	int* numAddr = new int;	// pointer variable declaration includes '*' and 'new' command
	*numAddr = 34;

	cout << num << " ";
	cout << *numAddr << endl;
	cout << numAddr << endl;

	delete numAddr;		// deletes the value that numAddr points to
	numAddr = nullptr;		// but use '0' in labs, quizzes, and homeworks

	return 0;
}