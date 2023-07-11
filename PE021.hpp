#include <bits/stdc++.h>
using namespace std;

int PE021(int num) {
	int res = 0;
	vector<int> d(num);
	function<int(int)> sumDiv = [] (int num) {
		int sum = num > 1;
		for (int i = 2; i * i <= num; i ++) {
			if (!(num % i)) {
				sum += i;
				if (i * i != num) {
					sum += num / i;
				}
			}
		}
		return sum;
	};
	for (int i = 1; i < num; i ++) {
		d[i] = sumDiv(i);
		if (d[i] < i && d[d[i]] == i) {
			res += i + d[i];
		}
	}
	return res;
}