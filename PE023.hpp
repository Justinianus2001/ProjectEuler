#include <bits/stdc++.h>
using namespace std;

int PE023(int num) {
	int res = 0, len;
	vector<int> v;
	vector<bool> can(num + 1);
	function<int(int)> sumDiv = [] (int num) {
		int sum = num > 1;
		for (int i = 2; i * i <= num; i ++) {
			if (!(num % i)) {
				sum += i;
				if (i * i != num) {
					sum += num / i;
				}
			}
		}
		return sum;
	};
	for (int i = 1; i <= num; i ++) {
		if (!can[i]) {
			res += i;
		}
		if (sumDiv(i) > i) {
			v.push_back(i);
			for (int x: v) {
				if (i + x > num) {
					break;
				}
				can[i + x] = true;
			}
		}
	}
	return res;
}