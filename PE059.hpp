#include <bits/stdc++.h>
using namespace std;

int PE059() {
	freopen("PE059.txt", "r", stdin);
	string str, cipher, special = ";:,.+[]/\'\"?-!() ";
	while (getline(cin, str, ',')) {
		cipher += stoi(str);
	}
	for (char ch1 = 'a'; ch1 <= 'z'; ch1 ++) {
		for (char ch2 = 'a'; ch2 <= 'z'; ch2 ++) {
			for (char ch3 = 'a'; ch3 <= 'z'; ch3 ++) {
				string key = {ch1, ch2, ch3}, convert = cipher;
				int len = convert.size();
				for (int i = 0; i < len; i ++) {
					convert[i] ^= key[i % 3];
					if (!isalnum(convert[i]) && special.find(convert[i]) == string::npos) {
						goto END;
					}
				}
				cin.clear();
				return accumulate(begin(convert), end(convert), 0);
				END:;
			}
		}
	}
	cin.clear();
	return -1;
}