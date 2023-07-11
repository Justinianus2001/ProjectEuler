#include <bits/stdc++.h>
using namespace std;

int PE061(int num) {
	int res = 0, from = pow(10, num - 1), to = pow(10, num);
	vector<vector<int>> con(pow(10, num >> 1));
	function<bool(int)> isTriangle = [] (int num) {
		int idx = sqrt(num << 1);
		return idx * (idx + 1) >> 1 == num;
	};
	function<bool(int)> isSquare = [] (int num) {
		int idx = sqrt(num);
		return idx * idx == num;
	};
	function<bool(int)> isPentagon = [] (int num) {
		int idx = (sqrt(num * 24 + 1) + 1) / 6;
		return idx * (idx * 3 - 1) >> 1 == num;
	};
	function<bool(int)> isHexagon = [] (int num) {
		int idx = (sqrt(num * 8 + 1) + 1) / 4;
		return idx * (idx * 2 - 1) == num;
	};
	function<bool(int)> isHeptagon = [] (int num) {
		int idx = (sqrt(num * 40 + 9) + 3) / 10;
		return idx * (idx * 5 - 3) >> 1 == num;
	};
	function<bool(int)> isOctagon = [] (int num) {
		int idx = (sqrt(num * 12 + 4) + 2) / 6;
		return idx * (idx * 3 - 2) == num;
	};
	for (int i = from; i < to; i ++) {
		if (isTriangle(i) || isSquare(i) || isPentagon(i) || isHexagon(i) || isHeptagon(i) || isOctagon(i)) {
			con[i / (int)pow(10, num >> 1)].push_back(i % (int)pow(10, num >> 1));
		}
	}
	from = pow(10, (num >> 1) - 1);
	to = pow(10, num >> 1);
	for (int i = from; i < to; i ++) {
		for (int j: con[i]) {
			for (int k: con[j]) {
				for (int l: con[k]) {
					for (int m: con[l]) {
						for (int n: con[m]) {
							if (find(begin(con[n]), end(con[n]), i) != end(con[n]) && min({i, j, k, l, m, n}) == i) {
								vector<int> lst = {i * to + j, j * to + k, k * to + l, l * to + m, m * to + n, n * to + i};
								do {
									if (isTriangle(lst[0]) + isSquare(lst[1]) + isPentagon(lst[2]) + isHexagon(lst[3]) + isHeptagon(lst[4]) + isOctagon(lst[5]) == 6) {
										res += accumulate(begin(lst), end(lst), 0);
										goto END; 
									}
								} while (next_permutation(begin(lst), end(lst)));
								END:;
							}
						}
					}
				}
			}
		}
	}
	return res;
}