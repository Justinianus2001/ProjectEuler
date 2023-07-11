/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	sieve(1000000);
	long long numFamily;	cin >> numFamily;
	for(long long prime: primes){
		vector<long long> lst[10];
		string str = to_string(prime);
		for(long long idx = 0; idx < str.length(); idx ++)
			lst[str[idx] - '0'].push_back(idx);
		for(long long digit = 0; digit < 10; digit ++){
			if(!lst[digit].size())		continue;
			long long cnt = 0;
			for(long long step = 0; step < 10; step ++){
				string copy = str;
				for(long long idx: lst[digit]){
					if(!idx && !step)	goto NEXT;
					copy[idx] = step + '0';
				}
				cnt += binary_search(begin(primes), end(primes), stoll(copy));
				NEXT:;
			}
			if(cnt == numFamily){	cout << prime;	goto END;	}
		}
	}
	END:;
	return EXIT_SUCCESS;
}
//	Title:	Problem 51 - Prime digit replacements
//	URL:	https://projecteuler.net/problem=51
//	Input:	8
//	Output:	121313
//	Lang:	C++