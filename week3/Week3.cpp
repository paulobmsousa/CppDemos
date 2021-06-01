
#include <iostream>
#include <string.h>
#include "Week3.h"
#include <string>
#include <vector>

using namespace std;


// METHODS  ..........................................................................................................

int week3() {
#pragma message("Week 3 Lab ..................................")
	cout << "Week 3 Lab .................................." << endl;
	//inputExampleFunction();
	//testAge1();
	//testAge2();
	//testDynamicMemory();
	//testNewInt();
	//testArrays();
	//testMemClass();
	testVector();
	return 0;
}

void testAge1() {
	int age;
	cout << "[Age test 1]...";
	cout << "Enter the age: ";
	if (cin >> age) {
		cout << "Age entered: " << age << "." << endl;
	}
	else {
		cout << "ERROR: Invalid age!";
	}
}


void testAge2() {
	int age;
	cout << "[Age test 2]...";
	cout << "Enter the age: ";
	try {
		cin >> age;
		cout << "Age entered: " << age << "." << endl;
		// You will call setAge(age);
	}
	catch (...) {
		cout << "ERROR: Invalid age!";
	}
}

void inputExampleFunction() {
	string name;
	cout << "Enter a name: ";
	while (!getline(cin, name)) {
		cout << "Error: please type a name";
		cin.clear();
		cin.ignore(256, '\n');
	}
	cout << "Name entered: " << name << endl;
}

void testDynamicMemory() {
	int* anInt = new int(5);
	cout << "Integer: " << *anInt << " - Address: " << anInt << endl;
	delete(anInt);
	///cout << "Integer: " << *anInt << " - Address: " << anInt << endl;
}

void testNewInt() {
	int num1(10);
	cout << "Integer: " << num1 << " - Address: " << &num1 << endl;
	int *num2 = new int(10);
	cout << "Integer: " << *num2 << " - Address: " << num2 << endl;
	int num3 = 10;
	cout << "Integer: " << num3 << " - Address: " << &num3 << endl;
	string name1 = "Eric";
	cout << "Name: " << name1 << " - Address: " << &name1 << endl;
	string name2 ("Eric");
	cout << "Name: " << name2 << " - Address: " << &name2 << endl;
}

void testArrays() {
	int size = 3;
	// Unidimensional
	cout << "Unidimensional array..." << endl;
	int* intArray1 = new int[size];
	cout << "Without initialization" << endl;
	for (int i = 0; i < size; i++)
		cout << "intArray1[" << i << "]=" << intArray1[i] << ", Add: " << (intArray1+i) << endl;
	cout << "With initialization" << endl;
	for (int i = 0; i < size; i++) {
		intArray1[i] = i;
		cout << "intArray1[" << i << "]=" << intArray1[i] << ", Add: " << &intArray1[i] << endl;
	}
	cout << "Add intArray1: " << intArray1 << endl;
	delete[] intArray1;
	// Bidimensional
	cout << "Bidimensional array..." << endl;
	int k = 0;
	int** intArray2 = new int* [size];
	for (int i = 0; i < size; i++) {
		intArray2[i] = new int[size];
		for (int j = 0; j < size; j++) {
			intArray2[i][j] = k++;
			cout << "intArray2[" << i << "," << j << "]=" 
				<< intArray2[i][j] << ", Add: " << &(intArray2[i][j]) << endl;
		}
	}
	cout << "Add intArray2: " << intArray2 << endl;
	for (int i = 0; i < size; i++)
		delete[] intArray2[i];
	delete[] intArray2;
}

class ClassTemp {
public:
	int a;
	bool b, c;
};

class ClassPack {
public:
	int a:2;
	bool b:1, c:1;
};

void testMemClass() {
	ClassTemp ct;
	int classsize = sizeof(ct);
	int totalsize = sizeof(int) + 2*sizeof(bool);
	cout << "Size of class: " << classsize << endl;
	cout << "Size of types: " << totalsize << endl;
	ClassPack cp;
	int classpack = sizeof(cp);
	cout << "Size of pack: " << classpack << endl;
}

void testVector() {
	int size = 3;
	vector<int> v;
	// Creating vector
	cout << "Vector without iterator..." << endl;
	for (int j=0; j<size; ++j)	{
		v.push_back(j);
		cout << v[j] << " " << endl;
	}
	// Using iterator
	vector<int>::iterator it;
	cout << "Vector with iterator..." << endl;
	for (it = v.begin(); it != v.end(); ++it) {
		cout << *it << " " << endl;
	}
}
