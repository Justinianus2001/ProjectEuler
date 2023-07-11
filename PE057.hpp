#include <bits/stdc++.h>
using namespace std;

int PE057(int expand) {
	int res = 0;
	string num = "1", deno = "2";
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
	while (expand --) {
		res += sumBig(num, deno).length() > deno.length();
		tie(num, deno) = make_pair(deno, sumBig(num, mulBig(deno, 2)));
	}
	return res;
}