#include <bits/stdc++.h>
using namespace std;

int PE017(int num) {
	int res = 0;
	function<string(int)> speak = [&] (int num) {
		string res;
		vector<string> lst10 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},
						lst1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		if (num >= 1000) {
			res += speak(num / 1000) + "Thousand";
			num %= 1000;
			if (num && res.find("And") == string::npos) {
				res += "And";
			}
		}
		if (num >= 100) {
			res += speak(num / 100) + "Hundred";
			num %= 100;
			if (num && res.find("And") == string::npos) {
				res += "And";
			}
		}
		if (num >= 20) {
			res += lst10[num / 10];
			num %= 10;
		}
		if (num && num < 20) {
			res += lst1[num];
		}
		return res;
	};
	for (int i = 1; i <= num; i ++) {
		res += speak(i).length();
	}
	return res;
}