/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, remain, cntCycle, *cache, bestDeno, maxCycle = 0;
	cin >> range;
	for(long long deno = 2; deno < range; deno ++){
		cache = new long long[deno](),
		remain = 1, cntCycle = 0;
		while(true){
			remain %= deno;
			if(!remain)				goto NEXT;
			if(cache[remain])		break;
			cache[remain] = cntCycle;
			while(remain < deno)	cntCycle ++, remain *= 10;
		}
		if(cntCycle - cache[remain] > maxCycle)
			bestDeno = deno, maxCycle = cntCycle - cache[remain];
		NEXT:;
	}
	cout << bestDeno;
	return EXIT_SUCCESS;
}
//	Title:	Problem 26 - Reciprocal cycles
//	URL:	https://projecteuler.net/problem=26
//	Input:	1000
//	Output:	983
//	Lang:	C++
