#include <bits/stdc++.h>
using namespace std;

long long PE024(int num, string str) {
	string res;
	int len = str.length();
	function<int(int)> fact = [] (int val) {
		int res = 1;
		for (int i = 2; i <= val; i ++) {
			res *= i;
		}
		return res;
	};
	num = (num - 1) % fact(len);
	sort(begin(str), end(str));
	while (len --) {
		int val = fact(len), pos = num / val;
		res += str[pos];
		num %= val;
		str.erase(pos, 1);
	}
	return stoll(res);
}