#include <bits/stdc++.h>
using namespace std;

int PE074(int num, int term) {
	int res = 0;
	vector<int> fact(10, 1);
	unordered_map<int, int> cnt;
	function<int(int)> sumFactDigit = [&] (int num) {
		int res = 0;
		while (num) {
			res += fact[num % 10];
			num /= 10;
		}
		return res;
	};
	for (int i = 2; i < 10; i ++) {
		fact[i] = fact[i - 1] * i;
	}
	cnt[169] = cnt[363601] = cnt[1454] = 3;
	cnt[871] = cnt[45361] = 2;
	cnt[872] = cnt[45362] = 2;
	for (int i = 1; i < num; i ++) {
		if (!cnt[i]) {
			vector<int> chain;
			int val = 0, cur = i;
			while (true) {
				int next = sumFactDigit(cur);
				if (cur == next) {
					break;
				}
				val ++;
				chain.push_back(cur);
				cur = next;
				if (cur < num && cnt[cur]) {
					val += cnt[cur];
					break;
				}
			}
			for (int x: chain) {
				if (x < num) {
					cnt[x] = val;
				}
				val --;
			}
		}
		res += cnt[i] == term;
	}
	return res;
}