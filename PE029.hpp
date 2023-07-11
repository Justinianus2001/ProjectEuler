#include <bits/stdc++.h>
using namespace std;

int PE029(int num) {
	unordered_map<double, bool> cnt;
	for (int i = 2; i <= num; i ++) {
		for (int j = 2; j <= num; j ++) {
			cnt[powl(i, j)] = true;
		}
	}
	return cnt.size();
}