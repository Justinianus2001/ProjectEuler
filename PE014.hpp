#include <bits/stdc++.h>
using namespace std;

int PE014(int num) {
	int res = 1, mx = 1;
	vector<int> cntChain(num);
	for (int i = 2; i < num; i ++) {
		long long val = i;
		int cnt = 1;
		while (val >= i) {
			val = val & 1 ? val * 3 + 1 : val >> 1;
			cnt ++;
		}
		cntChain[i] = cnt += cntChain[val];
		if (cnt > mx) {
			res = i;
			mx = cnt;
		}
	}
	return res;
}