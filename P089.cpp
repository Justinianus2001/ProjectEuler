/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P089.txt", "r", stdin);
	long long res = 0;
	string str;
	while(cin >> str)
		res += str.length() - num2Roman(roman2Num(str)).length();
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 89 - Roman numerals
//	URL:	https://projecteuler.net/problem=89
//	Input:	P089.txt
//	Output:	743
//	Lang:	C++