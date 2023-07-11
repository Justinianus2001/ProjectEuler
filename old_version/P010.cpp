/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range;	cin >> range;
	sieve(range);
	cout << accumulate(begin(primes), end(primes), 0LL);
	return EXIT_SUCCESS;
}
//	Title:	Problem 10 - Summation of primes
//	URL:	https://projecteuler.net/problem=10
//	Input:	2000000
//	Output:	142913828922
//	Lang:	C++
