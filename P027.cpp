/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, N, maxN = 0, resAB;
	cin >> range;	sieve(range);
	for(long long A = -1; A > - range; A --)
		for(long long B: primes){
			N = 0;
			while(isPrime(N * N + N * A + B))	N ++;
			if(N > maxN)	maxN = N, resAB = A * B;
		}
	cout << resAB;
	return EXIT_SUCCESS;
}
//	Title:	Problem 27 - Quadratic primes
//	URL:	https://projecteuler.net/problem=27
//	Input:	1000
//	Output:	-59231
//	Lang:	C++
