// File: Cimage.h
// Created by: Michael Napoli
// Created on: 9/6/2019
// Last modified on: 9/11/2019

/* Class type for command prompt capable images of cats. */

#include <iostream>
using namespace std;

class Cimage
{
private:
	int image_num;
	int color_num;
	
	void type1() {
		HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(hConsole, color_num);
		
		cout << "  /\\___/\\ " << endl;
		cout << " ( o   o ) " << endl;
		cout << " (  =^=  ) " << endl;
		cout << " (        ) " << endl;
		cout << " (         ) " << endl;
		cout << " (          ))))))))))) " << endl;
		
		SetConsoleTextAttribute(hConsole, 7);
	}
	void type2() {
		HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(hConsole, color_num);
		
		cout << " ((      /|_/| " << endl;
		cout << "  \\\\.._.'  , ,\\ " << endl;
		cout << "  /\\ | '.__ v / " << endl;
		cout << " (_ .   /   \"    " << endl;
		cout << "  ) _)._  _ / " << endl;
		cout << " '.\\ \\|( / (  " << endl;
		cout << "   '' ''\\\\ \\\\ " << endl;
		
		SetConsoleTextAttribute(hConsole, 7);
	}
	void type3() {
		HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(hConsole, color_num);
		
		cout << "   |\\      _,,,---,,_ " << endl;
		cout << "   /,`.-'`'    -.  ;-;;,_ " << endl;
		cout << "  |,4-  ) )-,_..;\\ (  `'-' " << endl;
		cout << " '---''(_/--'  `-'\\_) " << endl;
		
		SetConsoleTextAttribute(hConsole, 7);
	}
	void type4() {
		HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(hConsole, color_num);
		
		cout << "      \\    /\\ " << endl;
		cout << "       )  ( ') " << endl;
		cout << "      (  /  ) " << endl;
		cout << "       \\(__)| " << endl;
		
		SetConsoleTextAttribute(hConsole, 7);
	}
	void type5() {
		HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(hConsole, color_num);
		
		cout << "              __..--''``---....___   _..._    __ " << endl;
		cout << "    /// //_.-'    .-/\";  `        ``<._  ``.''_ `. / // / " << endl;
		cout << "   ///_.-' _..--.'_    \\                    `( ) ) // // " << endl;
		cout << "   / (_..-' // (< _     ;_..__               ; `' / /// " << endl;
		cout << "    / // // //  `-._,_)' // / ``--...____..-' /// / // " << endl;
		
		SetConsoleTextAttribute(hConsole, 7);
	}
	void type6() {
		HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(hConsole, color_num);
		
		cout << "   ____ " << endl;
		cout << "  (.   \\ " << endl;
		cout << "    \\  | " << endl;
		cout << "     \\ |___(\\--/) " << endl;
		cout << "   __/    (  . . ) " << endl;
		cout << "  \"'._.    '-.O.' " << endl;
		cout << "       '-.  \\ \"|\\ " << endl;
		cout << "          '.,,/'.,, " << endl;
		
		SetConsoleTextAttribute(hConsole, 7);
	}
	
public:
	Cimage() : color_num(7)  // automatically set color_num to base windows text color
	{ }

	void setImage(int temp_num, int temp_color) { 
		image_num = temp_num;
		color_num = temp_color;
	}
	
	void display_image(){
		if (image_num == 1) { this->type1(); }
		else if (image_num == 2) { this->type2(); }
		else if (image_num == 3) { this->type3(); }
		else if (image_num == 4) { this->type4(); }
		else if (image_num == 5) { this->type5(); }
		else if (image_num == 6) { this->type6(); }
	}
};