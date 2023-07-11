#include <bits/stdc++.h>
using namespace std;

int PE006(int num) {
	int res = 0, sum = 0;
	for (int i = 1; i <= num; i ++) {
		res += i * i;
		sum += i;
	}
	res = sum * sum - res;
	return res;
}