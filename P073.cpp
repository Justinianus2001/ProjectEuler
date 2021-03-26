/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;	cin >> range;
	for(long long numerator = 2; numerator <= range; numerator ++)
		for(long long denominator = numerator * 2 + 1; denominator < min(range + 1, numerator * 3); denominator ++)
			res += __gcd(numerator, denominator) == 1;
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 73 - Counting fractions in a range
//	URL:	https://projecteuler.net/problem=73
//	Input:	12000
//	Output:	7295372
//	Lang:	C++