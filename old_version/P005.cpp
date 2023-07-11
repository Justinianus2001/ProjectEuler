/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long Max, best = 1;		cin >> Max;
	for(long long num = 2; num <= Max; num ++)
		best *= num / __gcd(best, num);
	cout << best;
	return EXIT_SUCCESS;
}
//	Title:	Problem 5 - Smallest multiple
//	URL:	https://projecteuler.net/problem=5
//	Input:	20
//	Output:	232792560
//	Lang:	C++
