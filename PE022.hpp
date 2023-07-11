#include <bits/stdc++.h>
using namespace std;

int PE022() {
	freopen("PE022.txt", "r", stdin);
	int res = 0, len;
	vector<string> lst;
	string str;
	while (getline(cin, str, ',')) {
		lst.push_back(str.substr(1, str.length() - 2));
	}
	len = lst.size();
	sort(begin(lst), end(lst));
	for (int i = 0; i < len; i ++) {
		int sum = 0;
		for (char ch: lst[i]) {
			sum += ch - 'A' + 1;
		}
		res += sum * (i + 1);
	}
	cin.clear();
	return res;
}