/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long num;
	cin >> num;		num --;
	cout << sumMultiplesXBelowN(num, 3)
		  + sumMultiplesXBelowN(num, 5)
		  - sumMultiplesXBelowN(num, 15);
	return EXIT_SUCCESS;
}
//	Title:	Problem 1 - Multiples of 3 and 5
//	URL:	https://projecteuler.net/problem=1
//	Input:	1000
//	Output:	233168
//	Lang:	C++