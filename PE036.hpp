#include <bits/stdc++.h>
using namespace std;

int PE036(int num) {
	int res = 0;
	function<bool(string)> isPalind = [] (string str) {
		int len = str.length();
		for (int i = 0; i << 1 < len; i ++) {
			if (str[i] != str[len - i - 1]) {
				return false;
			}
		}
		return true;
	};
	function<string(int)> toBase2 = [] (int num) {
		string res;
		while (num) {
			res += num % 2 + '0';
			num >>= 1;
		}
		reverse(begin(res), end(res));
		return res;
	};
	for (int i = 1; i < num; i ++) {
		if (isPalind(to_string(i)) && isPalind(toBase2(i))) {
			res += i;
		}
	}
	return res;
}