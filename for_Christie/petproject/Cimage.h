// File: Cimage.h
// Created by: Michael Napoli
// Created on: 9/6/2019
// Last modified on: 

/* Class type for command prompt capable images of cats. */

#include <iostream>
using namespace std;

class Cimage
{
private:
	int image_num;
	
	void type1() {
		cout << "  /\\___/\\ " << endl;
		cout << " ( o   o )" << endl;
		cout << " (  =^=  )" << endl;
		cout << " (        )" << endl;
		cout << " (         )" << endl;
		cout << " (          )))))))))))" << endl;
	}
	
public:
	void setImageNum(int temp_num) { image_num = temp_num; }
	void display_image(){
		if (image_num == 1) { this->type1(); }
	}
};

/*
  /\___/\
 ( o   o )
 (  =^=  )
 (        )
 (         )
 (          )))))))))))
*/