#include <bits/stdc++.h>
using namespace std;

long long PE043() {
	long long res = 0;
	vector<int> lst = {1, 2, 3, 5, 7, 11, 13, 17};
	string s = "0123456789";
	int len = lst.size();
	do {
		for (int i = 1; i < len; i ++) {
			if (stoi(s.substr(i, 3)) % lst[i]) {
				goto END;
			}
		}
		res += stoll(s);
		END:;
	} while (next_permutation(begin(s), end(s)));
	return res;
}