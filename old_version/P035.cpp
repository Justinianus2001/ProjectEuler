/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;
	cin >> range;	sieve(range);
	long long *checked = new long long[range]();
	for(long long idx = 0; idx < primes.size(); idx ++){
		if(checked[idx])
			continue;
		long long prime = primes[idx], len = log10(prime), cur = 0, cnt = 0, num = prime / 10;
		bool ok = true;
		while(num){
			if(!((num % 10) % 2) || num % 10 == 5)
				goto NEXT;
			num /= 10;
		}
		do{
			long long pos = binary_search_getPos(begin(primes), end(primes), prime);
			if(pos == primes.size()){
				ok = false;
				break;
			}
			cnt += !checked[pos], checked[pos] = true;
			prime = (prime % 10) * pow(10, len - 1) + prime / 10;
		}while(++ cur < len);
		if(ok)
			res += cnt;
		NEXT:;
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 35 - Circular primes
//	URL:	https://projecteuler.net/problem=35
//	Input:	1000000
//	Output:	55
//	Lang:	C++