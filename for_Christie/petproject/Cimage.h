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
	void type2() {
		cout << " ((      /|_/| " << endl;
		cout << "  \\\\.._.'  , ,\\ " << endl;
		cout << "  /\\ | '.__ v / " << endl;
		cout << " (_ .   /   \"    " << endl;
		cout << "  ) _)._  _ / " << endl;
		cout << " '.\\ \\|( / ( mrf" << endl;
		cout << "   '' ''\\\\ \\\\ " << endl;
	}
	void type3() {
		cout << "   |\\      _,,,---,,_ " << endl;
		cout << "   /,`.-'`'    -.  ;-;;,_ " << endl;
		cout << "  |,4-  ) )-,_..;\\ (  `'-' " << endl;
		cout << " '---''(_/--'  `-'\\_) " << endl;
	}
	void type4() {
		cout << "      \\    /\\ " << endl;
		cout << "       )  ( ') " << endl;
		cout << "      (  /  ) " << endl;
		cout << "       \\(__)| " << endl;
	}
	void type5() {
		cout << "              __..--''``---....___   _..._    __ " << endl;
		cout << "    /// //_.-'    .-/\";  `        ``<._  ``.''_ `. / // / " << endl;
		cout << "   ///_.-' _..--.'_    \\                    `( ) ) // // " << endl;
		cout << "   / (_..-' // (< _     ;_..__               ; `' / /// " << endl;
		cout << "    / // // //  `-._,_)' // / ``--...____..-' /// / // " << endl;
	}
	
public:
	void setImageNum(int temp_num) { image_num = temp_num; }
	void display_image(){
		if (image_num == 1) { this->type5(); }
	}
};

/*
              __..--''``---....___   _..._    __
    /// //_.-'    .-/";  `        ``<._  ``.''_ `. / // /
   ///_.-' _..--.'_    \                    `( ) ) // //
   / (_..-' // (< _     ;_..__               ; `' / ///
    / // // //  `-._,_)' // / ``--...____..-' /// / // 
*/