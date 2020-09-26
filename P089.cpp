/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline int romanToNum(string str){
	int ans = 0;
	for(int idx = 0; idx < str.length(); idx ++){
		char cur = str[idx], next = str[idx + 1];
		if(cur == 'I')
			ans += next == 'V' || next == 'X' ? -1 : 1;
		if(cur == 'V')		ans += 5;
		if(cur == 'X')
			ans += next == 'L' || next == 'C' ? -10 : 10;
		if(cur == 'L')		ans += 50;
		if(cur == 'C')
			ans += next == 'D' || next == 'M' ? -100 : 100;
		if(cur == 'D')		ans += 500;
		if(cur == 'M')		ans += 1000;
	}
	return ans;
}

inline string numToRoman(int num){
	pair<int, string> rules[] = {
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
		{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
		{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
	};
	string ans;
	for(pair<int, string> cmp: rules)
		while(num >= cmp.first)
			num -= cmp.first, ans += cmp.second;
	return ans;
}

int main(){
	freopen("P089.txt", "r", stdin);
	string inp;
	int ans = 0;
	while(cin >> inp)
		ans += inp.length() - numToRoman(romanToNum(inp)).length();
	cout << ans;
	return 0;
}
//	Title:	Problem 89 - Roman numerals
//	URL:	https://projecteuler.net/problem=89
//	Input:	P089.txt
//	Output:	743
//	Lang:	C++
