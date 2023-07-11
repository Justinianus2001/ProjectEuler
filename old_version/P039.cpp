/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, A, B, C, sum, base, mx = 0, res = 0;
	cin >> range;
	long long *cache = new long long[range + 1]();
	for(long long M = 2; M * M <= range; M ++)
		for(long long N = 1 + (M % 2); N < M; N ++){
			if(__gcd(M, N) != 1)		continue;
			A = M * M - N * N, B = M * N * 2, C = M * M + N * N,
			sum = A + B + C, base = 1;
			while(base * sum <= range)	cache[base * sum] ++, base ++;
		}
	for(long long p = 12; p <= range; p ++)
		if(cache[p] > mx)
			mx = cache[p], res = p;
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 39 - Integer right triangles
//	URL:	https://projecteuler.net/problem=39
//	Input:	1000
//	Output:	840
//	Lang:	C++