/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long digits;	cin >> digits;
	cout << (digits == 1 ? 1 : ceil((log(10) * (digits - 1) + log(5) / 2) / log(PHI)));
	return EXIT_SUCCESS;
}
//	Title:	Problem 25 - 1000-digit Fibonacci number
//	URL:	https://projecteuler.net/problem=25
//	Input:	1000
//	Output:	4782
//	Lang:	C++
