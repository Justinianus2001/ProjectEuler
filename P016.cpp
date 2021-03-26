/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	bigInteger num = 2;
	long long exp;		cin >> exp;
	vector<long long> vll = num.pow(exp).getBigNum();
	cout << accumulate(begin(vll), end(vll), 0LL);
	return EXIT_SUCCESS;
}
//	Title:	Problem 16 - Power digit sum
//	URL:	https://projecteuler.net/problem=16
//	Input:	1000
//	Output:	1366
//	Lang:	C++
