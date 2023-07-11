/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long exp, range = 1, sum = 0;
	cin >> exp;
	while(range * pow(9, exp) >= pow(10, range - 1))	range ++;
	range *= pow(9, exp);
	cout << range;
	for(long long num = 2; num <= range; num ++)
		if(sumPowDigit(num, exp) == num)
			sum += num;
	cout << sum;
	return EXIT_SUCCESS;
}
//	Title:	Problem 30 - Digit fifth powers
//	URL:	https://projecteuler.net/problem=30
//	Input:	5
//	Output:	443839
//	Lang:	C++
