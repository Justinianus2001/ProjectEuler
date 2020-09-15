/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
using namespace std;

inline int __gcd(int lhs, int rhs){
	if(!rhs)	return lhs;
	return __gcd(rhs, lhs % rhs);
}

int main(){
	int inp, ans = 0;	cin >> inp;
	vector<int> v(inp + 1);
	for(int m = 2; m * m <= inp; m ++)
		for(int n = 1; n < m; n ++){
			if(!((m + n) % 2) || __gcd(m, n) != 1)		continue;
			int a = m * m - n * n,
				b = 2 * m * n,
				c = m * m + n * n,
				sum = a + b + c;
			for(int mul = 1; sum * mul <= inp; mul ++)
				v[sum * mul] ++;
		}
	for(int idx = 12; idx <= inp; idx ++)
		ans += (v[idx] == 1);
	cout << ans;
	return 0;
}
//	Title:	Problem 75 - Singular integer right triangles
//	URL:	https://projecteuler.net/problem=75
//	Input:	1500000
//	Output:	161667
//	Lang:	C++
