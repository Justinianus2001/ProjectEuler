#include <bits/stdc++.h>
using namespace std;

string PE079() {
	freopen("PE079.txt", "r", stdin);
	vector<vector<bool>> pre(10, vector<bool>(10)), suf(10, vector<bool>(10));
	string login, res;
	while (cin >> login) {
		int len = login.length();
		for (int i = 0; i < len; i ++) {
			int x = login[i] - '0';
			for (int j = i + 1; j < len; j ++) {
				int y = login[j] - '0';
				pre[x][y] = suf[y][x] = true;
			}
		}
	}
	for (int i = 0; i < 10; i ++) {
		for (int j = 0; j < 10; j ++) {
			if (pre[i][j] || suf[i][j]) {
				res += to_string(i);
				break;
			}
		}
	}
	int len = res.length();
	do {
		vector<int> idx(10, -1);
		for (int i = 0; i < len; i ++) {
			idx[res[i] - '0'] = i;
		}
		for (int i = 0; i < len; i ++) {
			int x = res[i] - '0';
			for (int j = i + 1; j < len; j ++) {
				int y = res[j] - '0';
				if ((pre[x][y] && idx[x] > idx[y]) || (suf[x][y] && idx[x] < idx[y])) {
					goto END;
				}
			}
		}
		cin.clear();
		return res;
		END:;
	} while (next_permutation(begin(res), end(res)));
	cin.clear();
	return "-1";
}