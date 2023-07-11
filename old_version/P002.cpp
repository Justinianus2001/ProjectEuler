/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, sum = 0, prev = 1, cur = 2, next, notEven = 0;
	cin >> range;
	while(cur <= range){
		if(!notEven)	sum += cur;
		next = cur + prev, prev = cur, cur = next,
		notEven = (notEven + 1) % 3;
	}
	cout << sum;
	return EXIT_SUCCESS;
}
//	Title:	Problem 2 - Even Fibonacci numbers
//	URL:	https://projecteuler.net/problem=2
//	Input:	4000000
//	Output:	4613732
//	Lang:	C++
