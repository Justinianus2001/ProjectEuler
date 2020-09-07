/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

int main(){
	int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200}, dp[100000] = {}, inp;
	cin >> inp;		dp[0] = 1;
	for(int coin: coins)
		for(int idx = 0; idx <= inp - coin; idx ++)
			dp[idx + coin] += dp[idx];
	cout << dp[inp];
	return 0;
}
//	Title:	Problem 31 - Coin sums
//	URL:	https://projecteuler.net/problem=31
//	Input:	200
//	Output:	73682
//	Lang:	C++
