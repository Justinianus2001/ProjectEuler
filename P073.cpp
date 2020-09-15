/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline int __gcd(int lhs, int rhs){
	if(!rhs)	return lhs;
	return __gcd(rhs, lhs % rhs);
}

int main(){
	int inp, ans = 0;	cin >> inp;
	for(int nume = 2; nume <= inp; nume ++)
		for(int deno = nume * 2 + 1; deno < min(inp + 1, nume * 3); deno ++)
			ans += __gcd(nume, deno) == 1;
	cout << ans;
	return 0;
}
//	Title:	Problem 73 - Counting fractions in a range
//	URL:	https://projecteuler.net/problem=73
//	Input:	12000
//	Output:	7295372
//	Lang:	C++
