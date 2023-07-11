/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	vector<long long> primes;
	long long idx;		cin >> idx;
	for(long long num = 2; primes.size() < idx; num += (num != 2) + 1){
		bool ok = true;
		for(long long prime: primes){
			if(prime * prime > num)		break;
			if(!(num % prime)){	ok = false;	break;	}
		}
		if(ok)		primes.push_back(num);
	}
	cout << primes.back();
	return EXIT_SUCCESS;
}
//	Title:	Problem 7 - 10001st prime
//	URL:	https://projecteuler.net/problem=7
//	Input:	10001
//	Output:	104743
//	Lang:	C++
