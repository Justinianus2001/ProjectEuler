/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long size, sum, val1, val2, val3;
	cin >> size;		size /= 2;
	val1 = size - 1, val2 = size, val3 = size + 1;
	!(val1 % 3) ? val1 /= 3 : !(val2 % 3) ? val2 /= 3 : val3 /= 3;
	sum = val1 * val2 * val3 + size * size * size * 5 + size * size * 10 + size * 9 + 1;
	cout << sum;
	return EXIT_SUCCESS;
}
//	Title:	Problem 28 - Number spiral diagonals
//	URL:	https://projecteuler.net/problem=28
//	Input:	1001
//	Output:	669171001
//	Lang:	C++
