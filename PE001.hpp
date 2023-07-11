#include <bits/stdc++.h>
using namespace std;

int PE001(int num) {
	int res = 0;
	for (int i = 1; i < num; i ++) {
		if (!(i % 3) || !(i % 5)) {
			res += i;
		}
	}
	return res;
}