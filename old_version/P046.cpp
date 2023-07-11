/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	sieve(1000000);
	long long start, val;	cin >> start;
	for(long long num = start + 2; ; num += 2){
		bool ok = false;
		for(long long prime: primes){
			val = sqrt((num - prime) / 2);
			if(val * val == (num - prime) / 2){		ok = true;	break;		}
		}
		if(!ok){	cout << num;	break;	}
	}
	return EXIT_SUCCESS;
}
//	Title:	Problem 46 - Goldbach's other conjecture
//	URL:	https://projecteuler.net/problem=46
//	Input:	1
//	Output:	5777
//	Lang:	C++