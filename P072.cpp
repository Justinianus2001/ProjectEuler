/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long res = 0, range;	cin >> range;
	vector<long long> phi(range + 1);
	iota(begin(phi), end(phi), 0LL);
	for(long long denominator = 2; denominator <= range; denominator ++){
		if(phi[denominator] == denominator)
			for(long long mul = 1; denominator * mul <= range; mul ++)
				phi[denominator * mul] -= phi[denominator * mul] / denominator;
		res += phi[denominator];
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 72 - Counting fractions
//	URL:	https://projecteuler.net/problem=72
//	Input:	1000000
//	Output:	303963552391
//	Lang:	C++