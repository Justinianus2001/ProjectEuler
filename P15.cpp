#include <iostream>
using namespace std;

int main(){
	long long dp[101][101] = {};
	int inp;
	cin >> inp;		inp ++;
	for(int idx1 = 1; idx1 <= inp; idx1 ++)
		for(int idx2 = 1; idx2 <= inp; idx2 ++)
			dp[idx1][idx2] = (idx1 == 1 && idx2 == 1 ? 1 : dp[idx1 - 1][idx2] + dp[idx1][idx2 - 1]);
	cout << dp[inp][inp];
	return 0;
}
//	Title:	Problem 15 - Lattice paths
//	URL:	https://projecteuler.net/problem=15
//	Time:	O(n^2)
//	Input:	20
//	Output:	137846528820
//	Lang:	C++
