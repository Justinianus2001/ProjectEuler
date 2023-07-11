/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long numPerm;
	string str, ans;
	cin >> str >> numPerm;
	numPerm = (numPerm - 1) % getFact(str.length());
	sort(begin(str), end(str));
	while(str.length()){
		long long fact = getFact(str.length() - 1), pos = numPerm / fact;
		ans += str[pos], numPerm %= fact, str.erase(pos, 1);
	}
	cout << ans;
	return EXIT_SUCCESS;
}
//	Title:	Problem 24 - Lexicographic permutations
//	URL:	https://projecteuler.net/problem=24
//	Input:	0123456789 1000000
//	Output:	2783915460
//	Lang:	C++
