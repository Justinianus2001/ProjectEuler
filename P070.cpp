/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <cfloat>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> primes;

inline void sieve(long long range){
	for(int num = 3; num <= range; num += 2){
		bool isPrime = true;
		for(int prime: primes){
			if(prime * prime > num)		break;
			if(!(num % prime)){	isPrime = false;	break;	}
		}
		if(isPrime)		primes.push_back(num);
	}
}

inline int log10(long long num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline bool isPermutation(long long lhs, long long rhs){
	if(log10(lhs) != log10(rhs))	return false;
	long long sumL = 0, sumR = 0;
	while(lhs || rhs)
		sumL += pow(10, lhs % 10), sumR += pow(10, rhs % 10),
		lhs /= 10, rhs /= 10;
	return sumL == sumR;
}

int main(){
	double minRatio = DBL_MAX;
	long long inp, ans = -1;	cin >> inp;
	sieve(inp / 3);
	for(int idx1 = 0; idx1 < primes.size(); idx1 ++)
		for(int idx2 = idx1 + 1; idx2 < primes.size(); idx2 ++){
			long long n = primes[idx1] * primes[idx2],
					phiN = (primes[idx1] - 1) * (primes[idx2] - 1);
			if(n >= inp)		break;
			double ratio = (double)n / phiN;
			if(isPermutation(n, phiN) && ratio < minRatio)
				ans = n, minRatio = ratio;
		}
	cout << ans;
	return 0;
}
//	Title:	Problem 70 - Totient permutation
//	URL:	https://projecteuler.net/problem=70
//	Input:	10000000
//	Output:	8319823
//	Lang:	C++
