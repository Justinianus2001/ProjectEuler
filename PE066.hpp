#include <bits/stdc++.h>
using namespace std;

int PE066(int range) {
	string mx = "0";
	int res;
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
	function<string(string, string)> mulBig2 = [&] (string x, string y) {
		string cnt = "0";
		int len = x.length();
		for (int i = len - 1; i >= 0; i --) {
			string temp = sumBig(mulBig(y, x[i] - '0'), cnt);
			x[i] = temp.back();
			temp.pop_back();
			cnt = temp == "" ? "0" : temp;
		}
		if (cnt != "0") {
			x = cnt + x;
		}
		return x;
	};
	function<bool(string, string)> greaterBig = [] (string x, string y) {
		int lenX = x.length(), lenY = y.length();
		if (lenX != lenY) {
			return lenX > lenY;
		}
		for (int i = 0; i < lenX; i ++) {
			if (x[i] != y[i]) {
				return x[i] > y[i];
			}
		}
		return false;
	};
	for (int d = 2; d <= range; d ++) {
		int sqrtD = sqrt(d);
		if (sqrtD * sqrtD != d) {
			int a = sqrtD, num = 0, deno = 1;
			vector<string> x = {"0", "1", to_string(a)}, y = {"0", "0", "1"};
			while (true) {
				num = deno * a - num;
				deno = (d - num * num) / deno;
				a = (sqrtD + num) / deno;
				x[0] = x[1];
				x[1] = x[2];
				x[2] = sumBig(mulBig(x[1], a), x[0]);
				y[0] = y[1];
				y[1] = y[2];
				y[2] = sumBig(mulBig(y[1], a), y[0]);
				if (mulBig2(x[2], x[2]) == sumBig(mulBig2(mulBig(y[2], d), y[2]), "1")) {
					break;
				}
			}
			if (greaterBig(x[2], mx)) {
				mx = x[2];
				res = d;
			}
		}
	}
	return res;
}