/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long num, idx, res = 1;
	cin >> num;
	while(num --){
		cin >> idx;
		res *= getChampernowneDigit(idx);
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 40 - Champernowne's constant
//	URL:	https://projecteuler.net/problem=40
//	Input:	7
//		1 10 100 1000 10000 100000 1000000
//	Output:	210
//	Lang:	C++