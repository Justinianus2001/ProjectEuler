#include <bits/stdc++.h>
using namespace std;

int PE055(int num) {
	int res = 0;
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
	function<bool(string)> isPalind = [] (string str) {
		int len = str.length();
		for (int i = 0; i << 1 < len; i ++) {
			if (str[i] != str[len - i - 1]) {
				return false;
			}
		}
		return true;
	};
	for (int i = 1; i < num; i ++) {
		string s = to_string(i);
		for (int j = 0; j < 50; j ++) {
			string t = s;
			reverse(begin(t), end(t));
			s = sumBig(s, t);
			if (isPalind(s)) {
				goto END;
			}
		}
		res ++;
		END:;
	}
	return res;
}