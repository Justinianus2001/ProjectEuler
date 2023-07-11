#include <bits/stdc++.h>
using namespace std;

int PE025(int num) {
	int res = 2;
	string a = "1", b = "1";
	function<string(string, string)> sumBig = [] (string x, string y) {
		int lenX = x.length(), lenY = y.length(), len = max(lenX, lenY), cnt = 0;
		x = string(max(lenY - lenX, 0), '0') + x;
		y = string(max(lenX - lenY, 0), '0') + y;
		for (int i = len - 1; i >= 0; i --) {
			x[i] += y[i] - '0' + cnt;
			cnt = 0;
			if (x[i] > '9') {
				x[i] -= 10;
				cnt = 1;
			}
		}
		if (cnt) {
			x = '1' + x;
		}
		return x;
	};
	while (b.length() < num) {
		tie(a, b) = make_pair(b, sumBig(a, b));
		res ++;
	}
	return res;
}