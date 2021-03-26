/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long digit, best = 0;	cin >> digit;
	for(long long num1 = pow(10, digit) - 1; num1 * num1 > best; num1 -= 2)
		for(long long num2 = num1; num1 * num2 > best; num2 -= 2)
			if(isPalindrome(num1 * num2))
				best = max(best, num1 * num2);
	cout << best;
	return EXIT_SUCCESS;
}
//	Title:	Problem 4 - Largest palindrome product
//	URL:	https://projecteuler.net/problem=4
//	Input:	3
//	Output:	906609
//	Lang:	C++
