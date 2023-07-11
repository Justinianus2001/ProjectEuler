/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	bigInteger numerator = 1, denominator = 2;
	int expand, res = 0;	cin >> expand;
	while(expand --){
		if((numerator + denominator).getLog10() > denominator.getLog10())
			res ++;
		numerator = numerator + denominator * 2, swap(numerator, denominator);
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 57 - Square root convergents
//	URL:	https://projecteuler.net/problem=57
//	Input:	1000
//	Output:	153
//	Lang:	C++