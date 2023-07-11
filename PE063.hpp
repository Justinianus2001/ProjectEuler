#include <bits/stdc++.h>
using namespace std;

int PE063() {
	int res = 0;
	for (int i = 1; ; i ++) {
		double mn = pow(10, i - 1), mx = pow(10, i);
		bool haveNew = false;
		for (int j = 1; pow(j, i) < mx; j ++) {
			if (pow(j, i) >= mn) {
				res ++;
				haveNew = true;
			}
		}
		if (!haveNew) {
			break;
		}
	}
	return res;
}