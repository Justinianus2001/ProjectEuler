#include <bits/stdc++.h>
using namespace std;

int PE034() {
	int res = 0;
	function<vector<int>(int)> getFactList = [] (int val) {
		vector<int> res = {1};
		for (int i = 1; i <= val; i ++) {
			res.push_back(res.back() * i);
		}
		return res;
	};
	vector<int> fact = getFactList(9);
	function<int(int)> sumFact = [&] (int num) {
		int res = 0;
		while (num) {
			res += fact[num % 10];
			num /= 10;
		}
		return res;
	};
	int len = 7 * fact[9];
	for (int i = 10; i <= len; i ++) {
		if (sumFact(i) == i) {
			res += i;
		}
	}
	return res;
}