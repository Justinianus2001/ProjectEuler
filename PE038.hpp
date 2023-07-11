#include <bits/stdc++.h>
using namespace std;

int PE038() {
	int res = 0, len = pow(10, 9 >> 1);
	for (int i = 1; i < len; i ++) {
		int val = 0;
		for (int j = 1; to_string(val).length() < 9; j ++) {
			val = val * (int)pow(10, to_string(i * j).length()) + i * j;
		}
		string str = to_string(val);
		sort(begin(str), end(str));
		if (str == "123456789") {
			res = max(res, val);
		}
	}
	return res;
}