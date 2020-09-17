/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <set>
using namespace std;

int main(){
	freopen("P079.txt", "r", stdin);
	set<char> prev[10], next[10];
	string login, ans;
	int length = 0;
	while(cin >> login)
		for(int back = 0; back < login.length(); back ++)
			for(int front = back + 1; front < login.length(); front ++)
				prev[login[front] - '0'].insert(login[back]),
				next[login[back] - '0'].insert(login[front]);
	for(int digit = 0; digit < 10; digit ++)
		length += prev[digit].size() || next[digit].size();
	ans = string(length, '-');
	for(int digit = 0; digit < 10; digit ++)
		if(prev[digit].size() || next[digit].size())
			ans[prev[digit].size()] = digit + '0';
	cout << ans;
	return 0;
}
//	Title:	Problem 79 - Coin partitions
//	URL:	https://projecteuler.net/problem=79
//	Input:	P079.txt
//	Output:	73162890
//	Lang:	C++
