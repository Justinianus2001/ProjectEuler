/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, maxLen = 0, res = -1, *primeSum;
	cin >> range;		sieve(range);
	primeSum = new long long[range / 2]();
	for(long long idx = 1; idx <= primes.size(); idx ++)
		primeSum[idx] = primeSum[idx - 1] + primes[idx - 1];
	for(long long last = 0; last < primes.size(); last ++){
		for(long long first = last - maxLen - 1; first >= 0; first --){
			if(primeSum[last] - primeSum[first] > range)
				break;
			if(binary_search(begin(primes), end(primes), primeSum[last] - primeSum[first]))
				maxLen = last - first,
				res = primeSum[last] - primeSum[first];
		}
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 50 - Consecutive prime sum
//	URL:	https://projecteuler.net/problem=50
//	Input:	1000000
//	Output:	997651
//	Lang:	C++