#include <bits/stdc++.h>
using namespace std;

int PE018(vector<vector<int>> tri) {
	int res = 0, height = tri.size();
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
	return res;
}