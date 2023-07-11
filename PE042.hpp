#include <bits/stdc++.h>
using namespace std;

int PE042() {
	freopen("PE042.txt", "r", stdin);
	int res = 0;
	string str;
	function<bool(int)> isTriangle = [] (int num) {
		int idx = sqrt(num << 1);
		return idx * (idx + 1) >> 1 == num;
	};
	while (getline(cin, str, ',')) {
		str = str.substr(1, str.length() - 2);
		int sum = 0;
		for (char ch: str) {
			sum += ch - 'A' + 1;
		}
		res += isTriangle(sum);
	}
	cin.clear();
	return res;
}