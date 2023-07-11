#include <bits/stdc++.h>
using namespace std;

long long PE015(int num) {
	vector<vector<long long>> grid(num + 1, vector<long long>(num + 1));
	for (int i = 0; i <= num; i ++) {
		for (int j = 0; j <= num; j ++) {
			if (!i && !j) {
				grid[i][j] = 1;
			} else if (!i) {
				grid[i][j] = grid[i][j - 1];
			} else if (!j) {
				grid[i][j] = grid[i - 1][j];
			} else {
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			}
		}
	}
	return grid.back().back();
}