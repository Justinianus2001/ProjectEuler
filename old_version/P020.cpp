/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	bigInteger num = 1;
	long long maxFact;		cin >> maxFact;
	for(long long fact = 2; fact <= maxFact; fact ++)
		num *= fact;
	vector<long long> vll = num.getBigNum();
	cout << accumulate(begin(vll), end(vll), 0LL);
	return EXIT_SUCCESS;
}
//	Title:	Problem 20 - Factorial digit sum
//	URL:	https://projecteuler.net/problem=20
//	Input:	100
//	Output:	648
//	Lang:	C++
