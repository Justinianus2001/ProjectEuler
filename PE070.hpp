#include <bits/stdc++.h>
using namespace std;

int PE070(int num) {
	int res;
	double mn = DBL_MAX;
	function<int(int)> getPhi = [] (int num) {
		int res = num;
		for (int i = 2; i * i <= num; i ++) {
			if (!(num % i)) {
				while (!(num % i)) {
					num /= i;
				}
				res -= res / i;
			}
		}
		if (num > 1) {
			res -= res / num;
		}
		return res;
	};
	for (int i = 2; i < num; i ++) {
		int phi = getPhi(i);
		double val = (double)i / phi;
		string x = to_string(i), y = to_string(phi);
		sort(begin(x), end(x));
		sort(begin(y), end(y));
		if (x == y && val < mn) {
			mn = val;
			res = i;
		}
	}
	return res;
}