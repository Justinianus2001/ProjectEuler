/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, cntLetter = 0;
	cin >> range;
	for(long long num = 1; num <= range; num ++)
		cntLetter += speak(num).length();
	cout << cntLetter;
	return EXIT_SUCCESS;
}
//	Title:	Problem 17 - Number letter counts
//	URL:	https://projecteuler.net/problem=17
//	Input:	1000
//	Output:	21124
//	Lang:	C++
