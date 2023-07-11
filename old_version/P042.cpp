/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P042.txt", "r", stdin);
	string str;		cin >> str;
	vector<string> words = tokenize(str, "\",\"");
	long long res = 0;
	for(string word: words){
		long long val = 0;
		for(char ch: word)	val += getCharIdx(ch);
		res += isTriangularVal(val);
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 42 - Coded triangle numbers
//	URL:	https://projecteuler.net/problem=42
//	Input:	P042.txt
//	Output:	162
//	Lang:	C++