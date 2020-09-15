/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes = {2};

inline void sieve(int range){
	for(int num = 3; num <= range; num += 2){
		bool isPrime = true;
		for(int prime: primes){
			if(prime * prime > num)		break;
			if(!(num % prime)){	isPrime = false;	break;	}
		}
		if(isPrime)		primes.push_back(num);
	}
}

int main(){
	sieve(10000);
	long long dp[100000] = {};
	int inp;	cin >> inp;
	dp[0] = 1;
	for(auto prev: primes)
		for(int cur = prev; cur <= 10000; cur ++)
			dp[cur] += dp[cur - prev];
	for(int num = 1; ; num ++)
		if(dp[num] >= inp){	cout << num;	break;	}
	return 0;
}
//	Title:	Problem 77 - Prime summations
//	URL:	https://projecteuler.net/problem=77
//	Input:	5000
//	Output:	71
//	Lang:	C++
