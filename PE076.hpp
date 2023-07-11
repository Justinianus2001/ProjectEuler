#include <bits/stdc++.h>
using namespace std;

int PE076(int num) {
	vector<int> dp(num + 1);
	dp[0] = 1;
	for (int j = 1; j < num; j ++) {
		for (int i = j; i <= num; i ++) {
			dp[i] += dp[i - j];
		}
	}
	return dp[num];
}