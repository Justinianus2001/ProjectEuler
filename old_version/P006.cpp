/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, val1, val2, val3;
	cin >> range;
	val1 = range, val2 = range + 1, val3 = range * range * 3 - range - 2;
	!(val1 % 2) ? val1 /= 2 : !(val2 % 2) ? val2 /= 2 : val3 /= 2;
	!(val1 % 2) ? val1 /= 2 : !(val2 % 2) ? val2 /= 2 : val3 /= 2;
	!(val1 % 3) ? val1 /= 3 : !(val2 % 3) ? val2 /= 3 : val3 /= 3;
	cout << val1 * val2 * val3;
	return EXIT_SUCCESS;
}
//	Title:	Problem 6 - Sum square difference
//	URL:	https://projecteuler.net/problem=6
//	Input:	100
//	Output:	25164150
//	Lang:	C++