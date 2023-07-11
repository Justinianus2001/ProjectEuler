#include <bits/stdc++.h>
using namespace std;

long long PE072(int num) {
	long long res = 0;
	vector<int> phi(num + 1);
	iota(begin(phi), end(phi), 0);
	for (int i = 2; i <= num; i ++) {
		if (phi[i] == i) {
			for (int j = 1; i * j <= num; j ++) {
				phi[i * j] -= phi[i * j] / i;
			}
		}
		res += phi[i];
	}
	return res;
}