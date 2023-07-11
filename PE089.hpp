#include <bits/stdc++.h>
using namespace std;

vector<pair<string, long long>> romanNumeral =
{{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
inline string num2Roman(long long num) {
	string res;
	for (pair<string, long long> roman: romanNumeral) {
		while (roman.second <= num) {
			res += roman.first;
			num -= roman.second;
		}
	}
	return res;
}

inline long long roman2Num(string roman) {
	long long res = 0;
	for (long long idx = 0; idx < roman.length(); ) {
		for (pair<string, long long> num: romanNumeral) {
			if (idx + num.first.length() <= roman.length() && roman.substr(idx, num.first.length()) == num.first) {
				res += num.second;
				idx += num.first.length();
				break;
			}
		}
	}
	return res;
}

int PE089() {
	freopen("PE089.txt", "r", stdin);
	int res = 0;
	string s;
	vector<pair<string, int>> romanNumeral = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
	function<string(int)> num2Roman = [&] (int num) {
		string res;
		for (pair<string, int> roman: romanNumeral) {
			while (roman.second <= num) {
				num -= roman.second;
				res += roman.first;
			}
		}
		return res;
	};
	function<int(string)> roman2Num = [&] (string str) {
		int res = 0, n = str.length();
		for (int i = 0; i < n; ) {
			for (pair<string, int> roman: romanNumeral) {
				if (i + roman.first.length() <= n && str.substr(i, roman.first.length()) == roman.first) {
					res += roman.second;
					i += roman.first.length();
					break;
				}
			}
		}
		return res;
	};
	while (cin >> s) {
		res += s.length() - num2Roman(roman2Num(s)).length();
	}
	cin.clear();
	return res;
}