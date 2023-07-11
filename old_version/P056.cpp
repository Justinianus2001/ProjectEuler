/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;	cin >> range;
	for(long long base = 0; base < range; base ++){
		bigInteger num = 1;
		for(long long exp = 0; exp < range; exp ++){
			num *= base;
			vector<long long> vll = num.getBigNum();
			res = max(res, accumulate(begin(vll), end(vll), 0LL));
		}
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 56 - Powerful digit sum
//	URL:	https://projecteuler.net/problem=56
//	Input:	100
//	Output:	972
//	Lang:	C++