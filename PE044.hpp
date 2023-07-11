#include <bits/stdc++.h>
using namespace std;

int PE044() {
	function<bool(int)> isPentagon = [] (int num) {
		int idx = (sqrt(num * 24 + 1) + 1) / 6;
		return idx * (idx * 3 - 1) >> 1 == num;
	};
	for (int i = 1; ; i ++) {
		for (int j = i - 1; j > 0; j --) {
			int x = i * (i * 3 - 1) / 2, y = j * (j * 3 - 1) / 2;
			if (isPentagon(x + y) && isPentagon(x - y)) {
				return x - y;
			}
		}
	}
	return -1;
}