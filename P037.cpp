/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long need, len, cnt = 0, res = 0;
	cin >> need;
	for(long long num = 11; cnt < need; num += 2)
		if(isPrime(num)){
			bool check = true;
			len = log10(num);
			for(long long del = 1; del < len; del ++)
				if(!isPrime(num / pow(10LL, del)) || !isPrime(num % pow(10LL, del))){
					check = false;	break;
				}
			if(check)	cnt ++, res += num;
		}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 37 - Truncatable primes
//	URL:	https://projecteuler.net/problem=37
//	Input:	11
//	Output:	748317
//	Lang:	C++