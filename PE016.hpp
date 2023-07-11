#include <bits/stdc++.h>
using namespace std;

int PE016(int num) {
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
	int res = 0;
	string val = "1";
	for (int i = 0; i < num; i ++) {
		val = sumBig(val, val);
	}
	for (char ch: val) {
		res += ch - '0';
	}
	return res;
}