#include <bits/stdc++.h>
using namespace std;

long long PE062(int num) {
	map<string, vector<long long>> perm;
	for (long long i = 1; ; i ++) {
		long long cube = i * i * i;
		string s = to_string(cube);
		sort(begin(s), end(s));
		perm[s].push_back(cube);
		if (perm[s].size() == num) {
			return perm[s].front();
		}
	}
	return -1;
}