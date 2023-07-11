#include <bits/stdc++.h>
using namespace std;

string PE049(int num) {
	string res;
	unordered_map<int, bool> check;
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 1001; i < num; i += 2) {
		if (!check[i] && isPrime(i)) {
			vector<int> lst = {i};
			string s = to_string(i);
			while (next_permutation(begin(s), end(s))) {
				int val = stoi(s);
				if (isPrime(val)) {
					lst.push_back(val);
				}
			}
			int len = lst.size();
			sort(begin(lst), end(lst));
			for (int x = 0; x < len; x ++) {
				for (int y = x + 1; y < len; y ++) {
					for (int z = y + 1; z < len; z ++) {
						if (lst[z] - lst[y] == lst[y] - lst[x]) {
							res = to_string(lst[x]) + to_string(lst[y]) + to_string(lst[z]);
						}
					}
				}
			}
			for (int x: lst) {
				check[x] = true;
			}
		}
	}
	return res;
}