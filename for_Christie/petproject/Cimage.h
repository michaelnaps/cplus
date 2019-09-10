// File: Cimage.h
// Created by: Michael Napoli
// Created on: 9/6/2019
// Last modified on: 9/7/2019

/* Class type for command prompt capable images of cats. */

#include <iostream>
using namespace std;

class Cimage
{
private:
	int image_num;
	
	void type1() {
		cout << "  /\\___/\\ " << endl;
		cout << " ( o   o ) " << endl;
		cout << " (  =^=  ) " << endl;
		cout << " (        ) " << endl;
		cout << " (         ) " << endl;
		cout << " (          ))))))))))) " << endl;
	}
	void type2() {
		cout << " ((      /|_/| " << endl;
		cout << "  \\\\.._.'  , ,\\ " << endl;
		cout << "  /\\ | '.__ v / " << endl;
		cout << " (_ .   /   \"    " << endl;
		cout << "  ) _)._  _ / " << endl;
		cout << " '.\\ \\|( / (  " << endl;
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
	void type6() {
		cout << "   ____ " << endl;
		cout << "  (.   \\ " << endl;
		cout << "    \\  | " << endl;
		cout << "     \\ |___(\\--/) " << endl;
		cout << "   __/    (  . . ) " << endl;
		cout << "  \"'._.    '-.O.' " << endl;
		cout << "       '-.  \\ \"|\\ " << endl;
		cout << "          '.,,/'.,, " << endl;
	}
	
public:
	void setImageNum(int temp_num) { image_num = temp_num; }
	void display_image(){
		if (image_num == 1) { this->type1(); }
		else if (image_num == 2) { this->type2(); }
		else if (image_num == 3) { this->type3(); }
		else if (image_num == 4) { this->type4(); }
		else if (image_num == 5) { this->type5(); }
		else if (image_num == 6) { this->type6(); }
	}
};