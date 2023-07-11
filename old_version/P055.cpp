/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;	cin >> range;
	for(long long num = 1; num < range; num ++){
		bigInteger bigNum = num;
		for(long long turn = 1; turn <= 50; turn ++){
			bigNum += bigNum.getReverseNum();
			if(isPalindrome(bigNum.toString()))
				goto NEXT;
		}
		res ++;
		NEXT:;
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 55 - Lychrel numbers
//	URL:	https://projecteuler.net/problem=55
//	Input:	10000
//	Output:	249
//	Lang:	C++