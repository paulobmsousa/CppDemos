# CMakeList.txt : CMake project for CppDemos, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CppDemos")
# New comment
add_executable (CppDemos
	"CppDemos.cpp" "CppDemos.h"
	"week1/Week1.cpp" "week1/Week1.h"
	"week2/Week2.cpp" "week2/Week2.h" "week3/Week3.cpp" "week3/Week3.h" "week3/Fraction.h" "week3/Fraction.cpp")

# TODO: Add tests and install targets if needed.

