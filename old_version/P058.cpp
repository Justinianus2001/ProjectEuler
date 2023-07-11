/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long num = 1, res = 3, cntPrime = 0, cntAll = 1;
	long double ratio;
	cin >> ratio;	ratio /= 100;
	while(true){
		for(long long corner = 0; corner < 4; corner ++)
			num += res - 1, cntAll ++, cntPrime += isPrime(num);
		if((long double)cntPrime / cntAll < ratio)
			break;
		res += 2;
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 58 - Spiral primes
//	URL:	https://projecteuler.net/problem=58
//	Input:	10
//	Output:	26241
//	Lang:	C++