/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;
	cin >> range;
	for(long long num = 2; num <= range; num ++){
		long long root = sqrt(num),
			numerator = 0, denominator = 1,
			A = root, cntPeriod = 0;
		if(root * root == num)	continue;
		while(A != root * 2)
			numerator = denominator * A - numerator,
			denominator = (num - numerator * numerator) / denominator,
			A = (root + numerator) / denominator,
			cntPeriod ++;
		res += cntPeriod % 2;
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 64 - Odd period square roots
//	URL:	https://projecteuler.net/problem=64
//	Input:	10000
//	Output:	1322
//	Lang:	C++