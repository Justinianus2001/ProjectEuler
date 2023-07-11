/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long need, *cache, coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	cin >> need;
	cache = new long long[need + 1](), cache[0] = 1;
	for(long long coin: coins)
		for(long long cost = coin; cost <= need; cost ++)
			cache[cost] += cache[cost - coin];
	cout << cache[need];
	return EXIT_SUCCESS;
}
//	Title:	Problem 31 - Coin sums
//	URL:	https://projecteuler.net/problem=31
//	Input:	200
//	Output:	73682
//	Lang:	C++
