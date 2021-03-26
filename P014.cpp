/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, *cache, cur, cnt, best = 0, val = 1;
	cin >> range;	cache = new long long[range]();
	for(long long num = 2; num < range; num ++){
		cur = num, cnt = 1;
		while(cur >= num)
			cur = (cur & 1 ? cur * 3 + 1 : cur / 2),
			cnt ++;
		cache[num] = cnt += cache[cur];
		if(cnt > best)	best = cnt, val = num;
	}
	cout << val;
	return EXIT_SUCCESS;
}
//	Title:	Problem 14 - Longest Collatz sequence
//	URL:	https://projecteuler.net/problem=14
//	Input:	1000000
//	Output:	837799
//	Lang:	C++
