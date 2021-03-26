/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P099.txt", "r", stdin);
	map<long double, long long> mp;
	string str;
	for(long long idx = 1; cin >> str; idx ++){
		vector<string> token = tokenize(str, ",");
		long long base = stoll(token[0]), exp = stoll(token[1]);
		mp[exp * log(base)] = idx;
	}
	cout << rbegin(mp)->second;
	return EXIT_SUCCESS;
}
//	Title:	Problem 99 - Largest exponential
//	URL:	https://projecteuler.net/problem=99
//	Input:	PT099.txt
//	Output:	709
//	Lang:	C++