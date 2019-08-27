//Lecture 4
//topics include: variable counters
/*
notes:
  -general syntax of a counter: variable += counterValue;
  -evaluates the expression and adds the counterValue to it automatically
  -variable++
    -increments the value of the variable by one unit
  -varaible--
    -decrements the value of the variable by one unit
  -that being said, use pre-increment operators more often - faster and more often correct
  -when a variable is not initialized, never assume its value
  -considered good practice to always assign a variable a value, even if it later gets overwritten
    -most often made to be 0
    Ex: int x = 0;
*/

#include <iostream>
using namespace std;

int main()
{
  int counter;
  int dogs = 3;
  int cats = 4;
  int i = 1;

  counter += 6;
  counter += dogs + cats; //adds the values of dogs and cats to the already established value of 6 and avoids repitition of variable names.
  
  cout << ++i << endl;
  i = 1;
  cout << i++ << endl;
}
