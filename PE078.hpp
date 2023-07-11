#include <bits/stdc++.h>
using namespace std;

int PE078(int num) {
	vector<int> p = {1};
	for (int i = 1; ; i ++) {
		int sign = 0, k = 1, pN = 0;
		while (k <= i) {
			pN = (pN + (sign ++ % 4 < 2 ? 1 : -1) * p[i - k]) % num;
			int cur = sign & 1 ? - sign / 2 - 1 : sign / 2 + 1;
			k = cur * (cur * 3 - 1) / 2;
		}
		if (!pN) {
			return i;
		}
		p.push_back(pN);
	}
	return -1;
}