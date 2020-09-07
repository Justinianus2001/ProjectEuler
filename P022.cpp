/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("P022.txt", "r", stdin);
	vector<string> names;
	int start = -1, stop, ans = 0, score;
	string inp;		cin >> inp;
	while((start = inp.find("\"", start + 1)) != string::npos){
		stop = inp.find("\"", start + 1);
		names.push_back(inp.substr(start + 1, stop - start - 1));
		start = stop;
	}
	sort(begin(names), end(names));
	for(int idx = 0; idx < names.size(); idx ++){
		score = 0;
		for(char ch: names[idx])
			score += ch - 'A' + 1;
		ans += score * (idx + 1);
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 22 - Names scores
//	URL:	https://projecteuler.net/problem=22
//	Input:	P022.txt
//	Output:	871198282
//	Lang:	C++
