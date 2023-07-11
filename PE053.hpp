#include <bits/stdc++.h>
using namespace std;

int PE053(int num, int range) {
	int res = 0;
	vector<vector<int>> pascal(num + 1);
	for (int i = 0; i <= num; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (!j || i == j) {
				pascal[i].push_back(1);
			} else {
				pascal[i].push_back(min(pascal[i - 1][j - 1] + pascal[i - 1][j], range + 1));
				res += pascal[i].back() > range;
			}
		}
	}
	return res;
}