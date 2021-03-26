/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	map<long double, int> mp;
	map<long double, int>::iterator it;
	long long range;	cin >> range;
	for(long long numerator = 1; numerator <= range; numerator ++){
		long long denominator = ceil(numerator / 3.0 * 7.0);
		if(denominator > range)	continue;
		if(__gcd(numerator, denominator) == 1)
			mp[(long double)numerator / denominator] = numerator;
	}
	it = mp.end();
	cout << (*----it).second;
	return EXIT_SUCCESS;
}
//	Title:	Problem 71 - Ordered fractions
//	URL:	https://projecteuler.net/problem=71
//	Input:	1000000
//	Output:	428570
//	Lang:	C++