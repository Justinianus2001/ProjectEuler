/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P022.txt", "r", stdin);
	long long sum = 0, score;
	string str;		cin >> str;
	vector<string> names = tokenize(str, "\",\"");
	sort(begin(names), end(names));
	for(long long idx = 0; idx < names.size(); idx ++){
		score = 0;
		for(char ch: names[idx])
			score += getCharIdx(ch);
		sum += score * (idx + 1);
	}
	cout << sum;
	return EXIT_SUCCESS;
}
//	Title:	Problem 22 - Names scores
//	URL:	https://projecteuler.net/problem=22
//	Input:	P022.txt
//	Output:	871198282
//	Lang:	C++
