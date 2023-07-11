#include <bits/stdc++.h>
using namespace std;

int PE065(int idx) {
	string num = "2", deno = "1";
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
	function<string(string, int)> mulBig = [] (string val, int num) {
		int cnt = 0, len = val.length();
		for (int i = len - 1; i >= 0; i --) {
			int temp = (val[i] - '0') * num + cnt;
			val[i] = temp % 10 + '0';
			cnt = temp / 10;
		}
		while (cnt) {
			val = (char)(cnt % 10 + '0') + val;
			cnt /= 10;
		}
		return val;
	};
	for (int i = 2; i <= idx; i ++) {
		int a = !(i % 3) ? i / 3 * 2 : 1;
		tie(num, deno) = make_pair(sumBig(mulBig(num, a), deno), num);
	}
	return accumulate(begin(num), end(num), 0) - '0' * num.length();
}