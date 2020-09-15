/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

int main(){
	int inp, dp[100000] = {};
	cin >> inp;		dp[0] = 1;
	for(int prev = 1; prev < inp; prev ++)
		for(int cur = prev; cur <= inp; cur ++)
			dp[cur] += dp[cur - prev];
	cout << dp[inp];
	return 0;
}
//	Title:	Problem 76 - Counting summations
//	URL:	https://projecteuler.net/problem=76
//	Input:	100
//	Output:	190569291
//	Lang:	C++
