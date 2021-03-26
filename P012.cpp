/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	sieve(100000);
	long long maxDiv, idx, D1 = 1, D2 = 1;
	cin >> maxDiv;
	for(idx = 2; D1 * D2 <= maxDiv; idx ++)
		if(!(idx % 2))
			D1 = cntDiv(idx + 1, primes);
		else
			D2 = cntDiv(idx / 2 + 1, primes);
	idx --;
	cout << getTriangularVal(idx);
	return EXIT_SUCCESS;
}
//	Title:	Problem 12 - Highly divisible triangular number
//	URL:	https://projecteuler.net/problem=12
//	Input:	500
//	Output:	76576500
//	Lang:	C++
