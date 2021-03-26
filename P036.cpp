/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;
	cin >> range;
	for(long long idx = 1; idx < range; idx ++)
		if(isPalindrome(idx) && isPalindrome(dec2Bin(idx)))
			res += idx;
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 36 - Double-base palindromes
//	URL:	https://projecteuler.net/problem=36
//	Input:	1000000
//	Output:	872187
//	Lang:	C++