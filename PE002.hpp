#include <bits/stdc++.h>
using namespace std;

int PE002(int num) {
	int res = 0;
	for (int a = 1, b = 2; b <= num; tie(a, b) = make_pair(b, a + b)) {
		res += b * !(b % 2);
	}
	return res;
}