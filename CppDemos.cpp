// CppDemos.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "CppDemos.h"

using namespace std;

/*
* Main function: Organizing according to weeks
*/

int main() {
#pragma message("Main -------------------------------")
	cout << "Starting Main -------------------------------" << endl;
	switch (WEEK) {
	case 1:
		week1();
		break;
	case 2:
		week2();
		break;
	case 3:
		week3();
		break;
	case 4:
		week4();
		break;
	case 5:
		week5();
	break;	default:
		cout << "Hello CMake." << endl;
	}
	cout << "Ending Main ---------------------------------" << endl;
	return EXIT_SUCCESS;
}
