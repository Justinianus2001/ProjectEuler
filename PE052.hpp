#include <bits/stdc++.h>
using namespace std;

int PE052(int num) {
	for (int i = 1; ; i ++) {
		string s = to_string(i);
		sort(begin(s), end(s));
		for (int mul = 2; mul <= num; mul ++) {
			string t = to_string(i * mul);
			sort(begin(t), end(t));
			if (s != t) {
				goto END;
			}
		}
		return i;
		END:;
	}
	return -1;
}