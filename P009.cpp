/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long sum, A, B, C, sumABC;
	cin >> sum;
	for(long long M = 2; M * M < sum; M ++)
		for(long long N = 1 + (M % 2); N < M; N += 2)
			if(__gcd(M, N) == 1){
				A = M * M - N * N, B = M * N * 2, C = M * M + N * N,
				sumABC = A + B + C;
				if(!(sum % sumABC))
					cout << A * B * C * pow(sum / sumABC, 3) << '\n';
			}
	return EXIT_SUCCESS;
}
//	Title:	Problem 9 - Special Pythagorean triplet
//	URL:	https://projecteuler.net/problem=9
//	Input:	1000
//	Output:	31875000
//	Lang:	C++
