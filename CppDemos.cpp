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
	cout << "Hello CMake." << endl;
	week1();
	;
	week2();
	cout << "Ending Main ---------------------------------" << endl;
	return EXIT_SUCCESS;
}
