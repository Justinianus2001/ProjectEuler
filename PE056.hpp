#include <bits/stdc++.h>
using namespace std;

int PE056(int num) {
	int res = 0;
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
	for (int i = 1; i < num; i ++) {
		string s = to_string(i);
		for (int j = 1; j < num; j ++) {
			s = mulBig(s, i);
			res = max(res, accumulate(begin(s), end(s), 0) - '0' * (int)s.length());
		}
	}
	return res;
}