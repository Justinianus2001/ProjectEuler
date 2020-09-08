/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

inline int __gcd(int lhs, int rhs){
	if(!rhs)	return lhs;
	return __gcd(rhs, lhs % rhs);
}

int main(){
	map<double, int>::iterator it;
	map<double, int> mp;
	int inp;	cin >> inp;
	for(double num = 1; num <= inp; num ++){
		double deno = (int)ceil(num / 3 * 7);
		if(deno > inp)	continue;
		if(__gcd(num, deno) == 1)
			mp[num / deno] = num;
	}
	it = mp.end(), it --, it --;
	cout << (*it).second;
	return 0;
}
//	Title:	Problem 71 - Ordered fractions
//	URL:	https://projecteuler.net/problem=71
//	Input:	1000000
//	Output:	428570
//	Lang:	C++
