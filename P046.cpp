/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <cmath>
using namespace std;

inline bool isPrime(int num){
	if(num == 2 || num == 3)			return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

int main(){
	bool ok;
	int inp, val;	cin >> inp;
	for(int idx = inp; ; idx += 2){
		if(isPrime(idx))		continue;
		ok = false;
		for(int prime = idx - 2; prime > 1; prime -= !(prime == 3) + 1)
			if(isPrime(prime)){
				val = sqrt((idx - prime) / 2);
				if(val * val == (idx - prime) / 2){		ok = true;	break;		}
			}
		if(!ok){	cout << idx;	break;	}
	}
	return 0;
}
//	Title:	Problem 46 - Goldbach's other conjecture
//	URL:	https://projecteuler.net/problem=46
//	Input:	3
//	Output:	5777
//	Lang:	C++
