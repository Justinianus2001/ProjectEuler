#include <bits/stdc++.h>
using namespace std;

int PE032(int num) {
	int res = 0;
	unordered_map<int, bool> cnt;
	for (int i = 1; to_string(i * i).length() <= num; i ++) {
		for (int j = i + 1; to_string(i * j).length() <= num; j ++) {
			string x = to_string(i), y = to_string(j), z = to_string(i * j);
			int n = x.length() + y.length() + z.length();
			if (n == num && !cnt[i * j]) {
				string s = x + y + z;
				sort(begin(s), end(s));
				for (int i = 0; i < n; i ++) {
					if (s[i] != '0' + i + 1) {
						goto NEXT;
					}
				}
				res += i * j;
				cnt[i * j] = true;
				NEXT:;
			} else if (n > num) {
				break;
			}
		}
	}
	return res;
}