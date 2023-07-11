#include <bits/stdc++.h>
using namespace std;

int PE071(int range, int num, int deno) {
	map<double, int> frac;
	for (int i = 1; i <= range; i ++) {
		int j = ceil((double)i / num * deno);
		if (i != num && j <= range && __gcd(i, j) == 1) {
			frac[(double)i / j] = i;
		}
	}
	return rbegin(frac)->second;
}