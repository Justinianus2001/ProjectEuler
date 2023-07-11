/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long num;		cin >> num;
	long long *cache = new long long[num + 1]();
	cache[0] = 1;
	for(long long prev = 1; prev < num; prev ++)
		for(long long cur = prev; cur <= num; cur ++)
			cache[cur] += cache[cur - prev];
	cout << cache[num];
	return EXIT_SUCCESS;
}
//	Title:	Problem 76 - Counting summations
//	URL:	https://projecteuler.net/problem=76
//	Input:	100
//	Output:	190569291
//	Lang:	C++