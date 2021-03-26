/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P081.txt", "r", stdin);
	vector<long long> v[500];
	long long cache[500][500];
	long long len = 0, width = 0;
	string str;
	while(cin >> str){
		vector<string> token = tokenize(str, ",");
		width = max(width, (long long)token.size());
		for(string num: token)	v[len].push_back(stoi(num));
		len ++;
	}
	for(long long row = 0; row < len; row ++)
		for(long long col = 0; col < width; col ++)
			cache[row][col] = LLONG_MAX;
	cache[0][0] = v[0][0];
	for(long long row = 0; row < len; row ++)
		for(long long col = 0; col < width; col ++){
			if(row)		cache[row][col] = min(cache[row][col], cache[row - 1][col] + v[row][col]);
			if(col)		cache[row][col] = min(cache[row][col], cache[row][col - 1] + v[row][col]);
		}
	cout << cache[len - 1][width - 1];
	return EXIT_SUCCESS;
}
//	Title:	Problem 81 - Path sum: two ways
//	URL:	https://projecteuler.net/problem=81
//	Input:	P081.txt
//	Output:	427337
//	Lang:	C++