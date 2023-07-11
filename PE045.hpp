#include <bits/stdc++.h>
using namespace std;

long long PE045(int num) {
	function<bool(long long)> isPentagon = [] (long long num) {
		long long idx = (sqrt(num * 24 + 1) + 1) / 6;
		return idx * (idx * 3 - 1) >> 1 == num;
	};
	function<bool(long long)> isHexagon = [] (long long num) {
		long long idx = (sqrt(num * 8 + 1) + 1) / 4;
		return idx * (idx * 2 - 1) == num;
	};
	for (long long idx = num + 1; ; idx ++) {
		long long val = idx * (idx + 1) >> 1;
		if (isPentagon(val) && isHexagon(val)) {
			return val;
		}
	}
	return -1;
}