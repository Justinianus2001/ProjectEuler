#include <bits/stdc++.h>
using namespace std;

int PE020(int num) {
	int res = 0;
	string val = "1";
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
	for (int i = 2; i <= num; i ++) {
		val = mulBig(val, i);
	}
	for (char ch: val) {
		res += ch - '0';
	}
	return res;
}