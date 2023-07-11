#include <bits/stdc++.h>
using namespace std;

int PE011(vector<vector<int>> grid, int num) {
	int res = 0, n = grid.size(), m = grid[0].size(), val;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (i + num <= n) {
				val = 1;
				for (int I = i; I < i + num; I ++) {
					val *= grid[I][j];
				}
				res = max(res, val);
			}
			if (j + num <= m) {
				val = 1;
				for (int J = j; J < j + num; J ++) {
					val *= grid[i][J];
				}
				res = max(res, val);
			}
			if (i + num <= n && j + num <= m) {
				val = 1;
				for (int I = i, J = j; I < i + num; I ++, J ++) {
					val *= grid[I][J];
				}
				res = max(res, val);
			}
			if (i + num <= n && j >= num - 1) {
				val = 1;
				for (int I = i, J = j; I < i + num; I ++, J --) {
					val *= grid[I][J];
				}
				res = max(res, val);
			}
		}
	}
	return res;
}