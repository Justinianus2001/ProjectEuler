/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P082.txt", "r", stdin);
	vector<long long> v[500];
	long long cache[500][500], res = LLONG_MAX;
	long long len = 0, width = 0;
	string str;
	while(cin >> str){
		vector<string> token = tokenize(str, ",");
		width = max(width, (long long)token.size());
		for(string num: token)	v[len].push_back(stoi(num));
		len ++;
	}
	for(long long col = 0; col < width; col ++){
		for(long long row = 0; row < len; row ++){
			cache[row][col] = v[row][col];
			if(col)		cache[row][col] += cache[row][col - 1];
		}
		for(long long rowDown = 1; rowDown < len; rowDown ++)
			cache[rowDown][col] = min(cache[rowDown][col], cache[rowDown - 1][col] + v[rowDown][col]);
		for(long long rowUp = len - 2; rowUp >= 0; rowUp --)
			cache[rowUp][col] = min(cache[rowUp][col], cache[rowUp + 1][col] + v[rowUp][col]);
	}
	for(long long row = 0; row < len; row ++)
		res = min(res, cache[row][width - 1]);
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 82 - Path sum: three ways
//	URL:	https://projecteuler.net/problem=82
//	Input:	P082.txt
//	Output:	260324
//	Lang:	C++