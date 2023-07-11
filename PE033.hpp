#include <bits/stdc++.h>
using namespace std;

int PE033(int num) {
	int resNum = 1, resDeno = 1, from = pow(10, num - 1), to = pow(10, num);
	for (int i = from; i < to; i ++) {
		for (int j = i + 1; j < to; j ++) {
			for (int k = 1; k < 10; k ++) {
				string x = to_string(i), y = to_string(j);
				x.erase(remove(begin(x), end(x), k + '0'), end(x));
				y.erase(remove(begin(y), end(y), k + '0'), end(y));
				if (x.length() && y.length() && to_string(i) != x && (double)i / j == (double)stoi(x) / stoi(y)) {
					resNum *= i;
					resDeno *= j;
				}
			}
		}
	}
	return resDeno / __gcd(resNum, resDeno);
}