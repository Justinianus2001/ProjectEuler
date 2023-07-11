/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P079.txt", "r", stdin);
	set<char> prev[10], next[10];
	string login, res;
	long long len = 0;
	while(cin >> login)
		for(long long back = 0; back < login.length(); back ++)
			for(long long front = back + 1; front < login.length(); front ++)
				prev[stoi(login[front])].insert(login[back]),
				next[stoi(login[back])].insert(login[front]);
	for(long long digit = 0; digit < 10; digit ++)
		len += prev[digit].size() || next[digit].size();
	res = string(len, '-');
	for(long long digit = 0; digit < 10; digit ++)
		if(prev[digit].size() || next[digit].size())
			res[prev[digit].size()] = digit + '0';
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 79 - Coin partitions
//	URL:	https://projecteuler.net/problem=79
//	Input:	P079.txt
//	Output:	73162890
//	Lang:	C++