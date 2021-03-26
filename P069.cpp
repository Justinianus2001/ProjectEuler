/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 1;
	cin >> range;
	for(long long num = 2; res * num <= range; num ++)
		if(isPrime(num))
			res *= num;
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 69 - Totient maximum
//	URL:	https://projecteuler.net/problem=69
//	Input:	1000000
//	Output:	510510
//	Lang:	C++