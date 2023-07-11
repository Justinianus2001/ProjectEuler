/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	sieve(10000);
	long long ways;	cin >> ways;
	long long *cache = new long long[10000]();
	cache[0] = 1;
	for(long long prime: primes)
		for(long long cur = prime; cur <= 10000; cur ++)
			cache[cur] += cache[cur - prime];
	for(long long num = 1; ; num ++)
		if(cache[num] >= ways){	cout << num;	break;	}
	return EXIT_SUCCESS;
}
//	Title:	Problem 77 - Prime summations
//	URL:	https://projecteuler.net/problem=77
//	Input:	5000
//	Output:	71
//	Lang:	C++