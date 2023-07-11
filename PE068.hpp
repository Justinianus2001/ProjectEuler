#include <bits/stdc++.h>
using namespace std;

string PE068(int num) {
	vector<int> inner(num), outer(num);
	vector<bool> choose(num << 1 | 1);
	string res;
	function<void(int)> Try = [&] (int idx) {
		if (idx == num << 1) {
			if (outer[num - 1] + inner[num - 1] == outer[0] + inner[1]) {
				string ans;
				for (int i = 0; i < num; i ++) {
					ans += to_string(outer[i]) + to_string(inner[i]) + to_string(inner[(i + 1) % num]);
				}
				res = max(res, ans);
			}
		} else {
			if (idx & 1) {
				for (int i = !!(idx >> 1) * outer[0] + 1; i <= num << 1; i ++) {
					if (!choose[i]) {
						outer[idx >> 1] = i;
						choose[i] = true;
						Try(idx + 1);
						choose[i] = false;
					}
				}
			} else {
				for (int i = 1; i <= num << 1; i ++) {
					if (!choose[i]) {
						inner[idx >> 1] = i;
						choose[i] = true;
						if (!idx || outer[(idx >> 1) - 1] + inner[(idx >> 1) - 1] + inner[idx >> 1] == outer[0] + inner[0] + inner[1]) {
							Try(idx + 1);
						}
						choose[i] = false;
					}
				}
			}
		}
	};
	Try(0);
	return res;
}