#include <bits/stdc++.h>
using namespace std;

long long PE008(string str, int num) {
	long long res = 0;
	int len = str.length();
	for (int i = 0; i + num < len; i ++) {
		long long val = 1;
		for (int j = i; j < i + num; j ++) {
			val *= str[j] - '0';
		}
		res = max(res, val);
	}
	return res;
}