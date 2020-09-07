/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline int __gcd(int lhs, int rhs){
	if(!rhs)	return lhs;
	return __gcd(rhs, lhs % rhs);
}

int main(){
	int inp, numerator = 1, denominator = 1, ans = 0;
	cin >> inp;
	for(int idx1 = pow(10, inp - 1); idx1 < pow(10, inp); idx1 ++){
		if(idx1 / 10 == idx1 % 10)		continue;
		for(int idx2 = idx1 + 1; idx2 < pow(10, inp); idx2 ++){
			if(idx2 / 10 == idx2 % 10)	continue;
			if((double)idx1 / idx2 == (double)(idx1 / 10) / (idx2 % 10) && idx1 % 10 == idx2 / 10)
				numerator *= idx1, denominator *= idx2;
		}
	}
	ans = denominator / __gcd(numerator, denominator);
	cout << ans;
	return 0;
}
//	Title:	Problem 33 - Digit cancelling fractions
//	URL:	https://projecteuler.net/problem=33
//	Input:	2
//	Output:	100
//	Lang:	C++
