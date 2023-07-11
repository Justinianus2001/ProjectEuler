/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	sieveCntDiv(10000000);
	long long numFact, curChain = 0;	cin >> numFact;
	for(long long num = 2; num <= 10000000; num ++)
		if(mapDiv[num] == numFact){
			if(++ curChain == numFact){	cout << num - numFact + 1;	break;	}
		}
		else{
			curChain = 0;
		}
	return EXIT_SUCCESS;
}
//	Title:	Problem 47 - Distinct primes factors
//	URL:	https://projecteuler.net/problem=47
//	Input:	4
//	Output:	134043
//	Lang:	C++