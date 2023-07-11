/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	sieve(100000);
	long long range, sum = 0, *cache;
	cin >> range;	cache = new long long[range];
	for(long long num = 1; num < range; num ++){
		cache[num] = sumDiv(num, primes);
		if(cache[num] < num && cache[cache[num]] == num)
			sum += num + cache[num];
	}
	cout << sum;
	return EXIT_SUCCESS;
}
//	Title:	Problem 21 - Amicable numbers
//	URL:	https://projecteuler.net/problem=21
//	Input:	10000
//	Output:	31626
//	Lang:	C++
