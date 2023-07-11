#include <bits/stdc++.h>
using namespace std;

int PE073(int range, int num1, int deno1, int num2, int deno2) {
	int res = 0;
	for (int i = 1; i <= range; i ++) {
		for (int j = i / num2 * deno2 + 1; j <= min(range, i / num1 * deno1 - 1); j ++) {
			res += __gcd(i, j) == 1;
		}
	}
	return res;
}