#include <bits/stdc++.h>
using namespace std;

int PE012(int num) {
	function<int(int)> cntDiv = [] (int val) {
		int res = 1;
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				int cnt = 1;
				while (!(val % i)) {
					val /= i;
					cnt ++;
				}
				res *= cnt;
			}
		}
		if (val != 1) {
			res <<= 1;
		}
		return res;
	};
	for (int val = 1, step = 2; ; val += step ++) {
		if (cntDiv(val) > num) {
			return val;
		}
	}
	return -1;
}