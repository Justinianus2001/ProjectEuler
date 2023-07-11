#include <bits/stdc++.h>
using namespace std;

int PE031(int num) {
	vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200}, dp(num + 1);
	dp[0] = 1;
	for (int coin: coins) {
		for (int i = coin; i <= num; i ++) {
			dp[i] += dp[i - coin];
		}
	}
	return dp[num];
}