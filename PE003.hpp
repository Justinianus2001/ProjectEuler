#include <bits/stdc++.h>
using namespace std;

int PE003(long long num) {
	int res = 0;
	while (res < num) {
		res += 1 + (res != 2);
		while (!(num % res)) {
			num /= res;
		}
	}
	return res;
}