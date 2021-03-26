/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	bigInteger numerator = 2, denominator = 1;
	long long targetIdx;	cin >> targetIdx;
	for(long long idx = 2; idx <= targetIdx; idx ++){
		long long a = !(idx % 3) ? (idx / 3) * 2 : 1;
		bigInteger temp = denominator;
		denominator = numerator,
		numerator = (denominator * a) + temp;
	}
	vector<long long> vll = numerator.getBigNum();
	cout << accumulate(begin(vll), end(vll), 0LL);
	return EXIT_SUCCESS;
}
//	Title:	Problem 65 - Convergents of e
//	URL:	https://projecteuler.net/problem=65
//	Input:	100
//	Output:	272
//	Lang:	C++