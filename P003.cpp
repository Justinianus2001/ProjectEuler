/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long num;		cin >> num;
	for(long long div = 2; div * div <= num; div += (div > 3) * 4 + (div > 2) + 1){
		while(!(num % div))			num /= div;
		while(!(num % (div + 2)))	num /= div + 2;
	}
	cout << num;
	return EXIT_SUCCESS;
}
//	Title:	Problem 3 - Largest prime factor
//	URL:	https://projecteuler.net/problem=3
//	Input:	600851475143
//	Output:	6857
//	Lang:	C++
