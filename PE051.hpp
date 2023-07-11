#include <bits/stdc++.h>
using namespace std;

int PE051(int num) {
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 2; ; i += 1 + (i != 2)) {
		if (isPrime(i)) {
			vector<int> pos[10];
			string s = to_string(i);
			int len = s.length();
			for (int i = 0; i < len; i ++) {
				pos[s[i] - '0'].push_back(i);
			}
			for (int j = 0; j < 10; j ++) {
				if (pos[j].size()) {
					int cnt = 0;
					for (int k = 0; k < 10; k ++) {
						if (j != k) {
							string t = s;
							for (int x: pos[j]) {
								t[x] = k + '0';
							}
							if (isPrime(stoi(t))) {
								cnt ++;
							}
						}
					}
					if (cnt == num) {
						return i;
					}
				}
			}
		}
	}
	return -1;
}