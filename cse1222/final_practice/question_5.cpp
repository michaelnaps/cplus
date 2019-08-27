// File: question #5
// Created by: Michael Napoli
// Created on: 7/27/19

/* For program use, please refer to cse 1222
practice final exam, question #5. */

#include <iostream>
using namespace std;

// FUNTION PROTOTYPE: count_0()
bool count_0(const double* a, const int size);

int main()
{
    int size(5);
    double arr[size];
    bool T_F;

    for (int i(0); i < size; ++i) {
        arr[i] = rand() % 3;
    }  

    T_F = count_0(arr, size);

    if (T_F) {
        cout << "There are more non-zero integers." << endl;
    }
    else { cout << "There are more 0's." << endl; }

    return 0;
}

// FUNCTION DEFINTION: count_0()
bool count_0(const double* a, const int size)
{
    int num_count(0);
    int zero_count(0);

    for (int i(0); i < size; ++i) {
        if (a[i] < 1.2e-5) {
            ++zero_count;
        }
        else { ++num_count; }
    }

    if (zero_count > num_count) { return false; }
    if (size == 0) { return false; }
    return true;
}