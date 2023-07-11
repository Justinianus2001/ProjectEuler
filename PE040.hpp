#include <bits/stdc++.h>
using namespace std;

int PE040(vector<int> pos) {
	int res = 1;
	string str;
	sort(begin(pos), end(pos));
	for (int i = 1; str.length() < pos.back(); i ++) {
		str += to_string(i);
	}
	for (int x: pos) {
		res *= str[x - 1] - '0';
	}
	return res;
}