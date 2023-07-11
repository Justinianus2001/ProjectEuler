#include <bits/stdc++.h>
using namespace std;

int PE005(int num) {
	int res = 1;
	for (int i = 2; i <= num; i ++) {
		res = res / __gcd(res, i) * i;
	}
	return res;
}