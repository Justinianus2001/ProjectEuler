/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	freopen("P042.txt", "r", stdin);
	vector<string> words;
	map<int, int> mp;
	int start = -1, stop, maxVal = 0, val, ans = 0;
	string inp;		cin >> inp;
	while((start = inp.find("\"", start + 1)) != string::npos){
		stop = inp.find("\"", start + 1);
		words.push_back(inp.substr(start + 1, stop - start - 1));
		start = stop;
	}
	for(string word: words){
		val = 0;
		for(char ch: word)	val += ch - 'A' + 1;
		maxVal = max(maxVal, val), mp[val] ++;
	}
	for(int idx = 1; idx * (idx + 1) / 2 <= maxVal; idx ++)
		ans += mp[idx * (idx + 1) / 2];
	cout << ans;
	return 0;
}
//	Title:	Problem 42 - Coded triangle numbers
//	URL:	https://projecteuler.net/problem=42
//	Input:	P042.txt
//	Output:	162
//	Lang:	C++
