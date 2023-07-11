#include <bits/stdc++.h>
using namespace std;

int PE009(int num) {
	int res = 0;
	for (int i = 3; i <= num; i ++) {
		for (int j = i + 1; j < num - i - j; j ++) {
			int k = num - i - j;
			if (i * i + j * j == k * k) {
				res = max(res, i * j * k);
			}
		}
	}
	return res;
}