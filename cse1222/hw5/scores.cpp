/*
  File: scores.cpp
  Created by: Michael Napoli
  Creation Date: 7/10/19
  Synopsis: Program that takes user inputted grades for three exams and finds the:
	-total score of the three exams
	-average score of the student scores
	-lowest score
	-highest score
	-amount of students who scored above average
	-prints an organized table that reports the aforementioned data
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// FUNCTION PROTOTYPE: read_list()
void exam_scores_3(int* arr1, int* arr2, int* arr3, const int length);

// FUNCTION PROTOTYPE: add_arrays()
void add_arrays(int* arr_total, const int* arr1, const int* arr2, const int* arr3, const int length);

//FUNCTION PROTOTYPE: arr_avg()
double arr_avg(const int* arr, const int length);

// FUNCTION PROTOTYPE: arr_min()
int arr_min(const int* arr, const int length);

// FUNCTION PROTOTYPE: arr_max()
int arr_max(const int* arr, const int length);

// FUNCTION PROTOTYPE: above_val()
int above_val(const double val, const int* arr, const int length);

// FUNCTION PROTOTYPE: print_grade_table()
void print_score_table(const int* arr1, const int* arr2, const int* arr3, const int* total, 
	const int length, const double average, const int low, const int high, const int above);

// FUNCTION PROTOTYPE: display_table_top()
void display_table_top();

// FUNCTION PROTOTYPE: display_student_scores()
void display_student_scores(const int* arr1, const int* arr2, const int* arr3, const int* total_arr, 
	const int num, const double average);

// FUNCTION PROTOTYPE: display_table_bottom()
void display_table_bottom(const int num, const double average, const int max, const int min,
	const int above);
	
int main()
{
	int * scores1;
	int * scores2;
	int * scores3;
	int * totals;
	int students(0);
	double avg(0.0);
	int min, max, above;
	
	// Prompt for the number of students
	cout << "Enter number of students: ";
	cin >> students; cout << endl;

	// Allocate arrays to hold exam scores and totals
	scores1 = new int[students];
	scores2 = new int[students];
	scores3 = new int[students];
	totals = new int[students];

	// Prompt and read exams for each student
	exam_scores_3(scores1, scores2, scores3, students);

	// Compute exam totals for each student
	add_arrays(totals, scores1, scores2, scores3, students);

	// Compute the average of the total scores
	avg = arr_avg(totals, students);

	// Find the minimum total score
	min = arr_min(totals, students);
	
	// Find the maximum total score
	max = arr_max(totals, students);
	
	// Compute the number of students with total scores at or above the average of the total scores
	above = above_val(avg, totals, students);

	// Display table
	print_score_table(scores1, scores2, scores3, totals, students,(double) avg, min, max, above);

	// De-allocate arrays
	delete[] scores1;
	delete[] scores2;
	delete[] scores3;
	delete[] totals;

	return 0;
}

// FUNCTION DEFINITION: read_list()
// function that reads student test scores for three exams into three different arrays
// 'arr1', 'arr2', 'arr3' - array pointers for the beginning of the exam arrays
// 'length' - number of array elements
void exam_scores_3(int* arr1, int* arr2, int* arr3, const int length)
{
	// for all array elements
	for (int k(0); k < length; ++k) {
		cout << "Enter the three exam scores for student #" << k + 1 << ": ";
		cin >> arr1[k];  // assign student scores to approriate arrays for exams 1, 2 and 3
		cin >> arr2[k];
		cin >> arr3[k];
	}
	
	cout << endl;

	return;  // return nothing
}

// FUNCTION DEFINITION: add_arrays()
// function that adds three inputted arrays into a single array
// 'arr_total' - array pointer that hold the total score for each student
// 'arr1', 'arr2', 'arr3' - array pointers for the beginning of the exam arrays
// 'length' - number of array elements
void add_arrays(int* arr_total, const int* arr1, const int* arr2, const int* arr3, const int length)
{
	// for all elements of the given arrays
	for (int i(0); i < length; ++i) {
		arr_total[i] = arr1[i] + arr2[i] + arr3[i];  // add elements together to make total score
	}

	return;  // return nothing
}

// FUNCTION DEFINITION: arr_avg
// function that ouputs the average value of a given array
// 'arr' - given array pointer
// 'length' - number of elements in array
double arr_avg(const int* arr, const int length)
{
	int sum(0);  // variable initialization for what will be the sum of all array values

	// for loop that iterates over the given array
	for (int i(0); i < length; ++i) {
		sum += arr[i];  // every array element is added to variable 'sum' which was initialized at 0
	}

	return ((double)sum / (double)length);  // return the average, or the sum divided by the number of array elements
}

// FUNCTION DEFINITION: arr_min()
// functions that finds the smallest number within a given array
// 'arr' - given array pointer
// 'length' - number of elements in array
int arr_min(const int* arr, const int length)
{
	int min(arr[0]);  // variable 'min' initialized at 'arr[0]' so that final answer will be correct

	// for loop that iterates over given array elements
	for (int i(0); i < length; ++i) {
		if (arr[i] < min) {  // if current array element is smaller then 'min' value
			min = arr[i];  // make 'min' equal to that element
		}
	}

	return min;  // return minimum value in the array
}

// FUNCTION DEFINITION: arr_max()
// functions that finds the largest number within a given array
// 'arr' - given array pointer
// 'length' - number of elements in array
int arr_max(const int* arr, const int length)
{
	int max(arr[0]);  // variable 'max' initialized at 'arr[0]' so that final answer will be correct

	// for loop that iterates over given array elements
	for (int i(0); i < length; ++i) {
		if (arr[i] > max) {  // if current array element is larger then 'max' value
			max = arr[i];  // make 'max' equal to that element
		}
	}

	return max;  // return maximum value in the array
}

// FUNCTION DEFINITION: above_val()
// function that counts the number of array elements above a given value
// 'val' - value given by program that is evaluated
// 'arr' - given array pointer
// 'length' - number of elements in array
int above_val(const double val, const int* arr, const int length)
{
	// element for number of instances that array element is greater then or equal to value
	int num_above(0);  // intitialized at 0 so it can be used as a counter

	// for all array elements
	for (int i(0); i < length; ++i) {
		if (arr[i] >= val) {  // if array element is larger then value
			++num_above;  // iterate 'num_above' by one
		}
	}

	return num_above;  // return number of instances
}

// FUNCTION DEFINITION: print_score_table()
// function that uses branch functions to print a table of score values
// 'arr1', 'arr2', 'arr3' - array pointers for the beginning of the exam arrays
// 'total' - array pointer that hold the total score for each student
// 'length' - number of array elements
// 'average' - average value of the total array
// 'low' - lowest score found in the total array
// 'high' - highest score found in the total array
// 'above' - number of instances that an array element is larger than the average
void print_score_table(const int* arr1, const int* arr2, const int* arr3, const int* total,
	const int length, const double average, const int low, const int high, const int above)
{
	// display top of table using helper function
	display_table_top();

	// for loop that iterates for every student and displays middle of table using helper function
	for (int i(0); i < length; ++i) {
		display_student_scores(arr1, arr2, arr3, total, i, average);
	}

	// diplay bottom of table using helper function
	display_table_bottom(length, average, high, low, above);

	return;  // return nothing
}

// FUNCTION DEFINITION: display_table_top()
// function that diplays the top of the table
// no inputs or outputs
void display_table_top()
{
	// function line that displays a staright line of characters "-"
	cout << setfill('-') << setw(50) << "  " << setfill(' ') << endl;

	// output for collumn headings
	cout << setw(8) << "Students"
		<< setw(10) << "Score 1" 
		<< setw(10) << "Score 2" 
		<< setw(10) << "Score 3" 
		<< setw(8) << "Total" << endl;

	// function line that displays a staright line of characters "-"
	cout << setfill('-') << setw(50) << "  " << setfill(' ') << endl;
	
	return;  // return nothing
}

// FUNCTION DEFINITION: display_student_scores
// function that ouputs all students individual scores in table format
// 'arr1', 'arr2', 'arr3' - array pointers for the beginning of the exam arrays
// 'total' - array pointer that hold the total score for each student
// 'num' - current array element needed to display appropriate student's scores
// 'average' - average value of the total array
void display_student_scores(const int* arr1, const int* arr2, const int* arr3, const int* total_arr,
	const int num, const double average)
{
	// output statements for:
	// student number
	cout << setw(8) << right << num + 1 << "   ";
	// exam 1 score
	cout << setw(10) << left << arr1[num];
	// exam 2 score
	cout << setw(10) << left << arr2[num];
	// exam 3 score
	cout << setw(10) << left << arr3[num];
	// total of the three exam scores
	cout << setw(6) << left << total_arr[num];

	// if the total score is:
	if (total_arr[num] > average) { // greater than average
		cout << '+';  // output "+" sign
	}
	else if (total_arr[num] < average) {  // less than the average
		cout << '-';  // output "-" sign
	}
	else {  // equal to the average (otherwise)
		cout << '=';  // output "=" sign
	}

	cout << endl; // endline

	return;  // return nothing
}

// FUNCTION DEFINITION: display_table_bottom()
// function that prints the bottom of a table with the given values
// 'num' - number of evaluated array elements
// 'average' - average of array elements
// 'max' - highest given value
// 'min' - lowest given vlaue
// 'above' - number of values greater than or equal to average
void display_table_bottom(const int num, const double average, const int max, const int min,
	const int above)
{
	// output dashed line
	cout << setfill('-') << setw(50) << right << "  " << setfill(' ') << endl;

	// output formatted number of students
	cout << setw(41) << left << "The number of students is:";
	cout << num << endl;

	// output average score
	cout << setw(41) << left << "The avg total score (rounded) is:";
	cout << round(average) << endl;

	// output max
	cout << setw(41) << left << "The maximum total score is:";
	cout << max << endl;

	// output min
	cout << setw(41) << left << "The minimum total score is:";
	cout << min << endl;

	// output number above max
	cout << setw(41) << left << "Total scores at or above the avg is:";
	cout << above << endl;

	// output dashed line
	cout << setfill('-') << setw(50) << right << "  " << setfill(' ') << endl;

	return;  // return nothing
}