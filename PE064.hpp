#include <bits/stdc++.h>
using namespace std;

int PE064(int range) {
	int res = 0;
	for (int i = 2; i <= range; i ++) {
		int root = sqrt(i), num = 0, deno = 1, a = root, cnt = 0;
		if (root * root != i) {
			while (a != root << 1) {
				num = deno * a - num;
				deno = (i - num * num) / deno;
				a = (root + num) / deno;
				cnt ++;
			}
		}
		res += cnt & 1;
	}
	return res;
}