// File: Cimage.h
// Created by: Michael Napoli
// Created on: 9/6/2019
// Last modified on: 1/20/2021

/*
	Class type for command prompt capable ASCII images of cats.
	For all image types: the rules of 'type1()' applies.
*/

#include <iostream>
using namespace std;

class Cimage
{
private:
	int image_num;  // for keeping track of the image number

	// image #1
	void type1() {
		// output image
		cout << "  /\\___/\\ " << endl;
		cout << " ( o   o ) " << endl;
		cout << " (  =^=  ) " << endl;
		cout << " (        ) " << endl;
		cout << " (         ) " << endl;
		cout << " (          ))))))))))) " << endl;
	}

	// image #2
	void type2() {
		cout << " ((      /|_/| " << endl;
		cout << "  \\\\.._.'  , ,\\ " << endl;
		cout << "  /\\ | '.__ v / " << endl;
		cout << " (_ .   /   \"    " << endl;
		cout << "  ) _)._  _ / " << endl;
		cout << " '.\\ \\|( / (  " << endl;
		cout << "   '' ''\\\\ \\\\ " << endl;
	}

	// image #3
	void type3() {
		cout << "   |\\      _,,,---,,_ " << endl;
		cout << "   /,`.-'`'    -.  ;-;;,_ " << endl;
		cout << "  |,4-  ) )-,_..;\\ (  `'-' " << endl;
		cout << " '---''(_/--'  `-'\\_) " << endl;
	}

	// image #4
	void type4() {
		cout << "      \\    /\\ " << endl;
		cout << "       )  ( ') " << endl;
		cout << "      (  /  ) " << endl;
		cout << "       \\(__)| " << endl;
	}

	// image #5
	void type5() {
		cout << "              __..--''``---....___   _..._    __ " << endl;
		cout << "    /// //_.-'    .-/\";  `        ``<._  ``.''_ `. / // / " << endl;
		cout << "   ///_.-' _..--.'_    \\                    `( ) ) // // " << endl;
		cout << "   / (_..-' // (< _     ;_..__               ; `' / /// " << endl;
		cout << "    / // // //  `-._,_)' // / ``--...____..-' /// / // " << endl;
	}

	// image #6
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

	// image #7
	void type7() {
		cout << "   /\\_/\\ " << endl;
		cout << "  ( o.o ) " << endl;
		cout << "   > ^ < " << endl;
	}

public:
	// choose image and color (public function)
	void setImage(int temp_num) {
		image_num = temp_num;
	}

	// display image based on 'image_num' inputted from function call
	void display_image(){
		if (image_num == 1) { this->type1(); }
		else if (image_num == 2) { this->type2(); }
		else if (image_num == 3) { this->type3(); }
		else if (image_num == 4) { this->type4(); }
		else if (image_num == 5) { this->type5(); }
		else if (image_num == 6) { this->type6(); }
		else if (image_num == 7) { this->type7(); }
	}
};
