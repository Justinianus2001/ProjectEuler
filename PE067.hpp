#include <bits/stdc++.h>
using namespace std;

int PE067() {
	freopen("PE067.txt", "r", stdin);
	int res = 0, val;
	vector<vector<int>> tri;
	for (int i = 0; cin >> val; i ++) {
		tri.push_back({val});
		for (int j = 0; j < i; j ++) {
			cin >> val;
			tri[i].push_back(val);
		}
	}
	int height = tri.size();
	for (int i = 0; i < height; i ++) {
		int width = i + 1;
		for (int j = 0; j < width; j ++) {
			if (!i && !j) {
				continue;
			} else if (!j) {
				tri[i][j] += tri[i - 1][j];
			} else if (i == j) {
				tri[i][j] += tri[i - 1][j - 1];
			} else {
				tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
			}
			res = max(res, tri[i][j]);
		}
	}
	cin.clear();
	return res;
}