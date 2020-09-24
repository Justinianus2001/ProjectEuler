/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <cmath>
#include <iostream>
#include <set>
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
	set<int> s;
	int inp;	cin >> inp;
	sieve(sqrt(inp));
	for(int primeA: primes){
		int start = primeA * primeA;
		if(start > inp)		break;
		for(int primeB: primes){
			int next = start + primeB * primeB * primeB;
			if(next > inp)		break;
			for(int primeC: primes){
				int last = next + primeC * primeC * primeC * primeC;
				if(last > inp)		break;
				s.insert(last);
			}
		}
	}
	cout << s.size();
	return 0;
}
//	Title:	Problem 87 - Prime power triples
//	URL:	https://projecteuler.net/problem=87
//	Input:	50000000
//	Output:	1097343
//	Lang:	C++
