/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long target, blue = 3, all = 4;
	cin >> target;
	while(all < target){
		long long nextBlue = blue * 3 + all * 2 - 2,
			nextAll = blue * 4 + all * 3 - 3;
		blue = nextBlue, all = nextAll;
	}
	cout << blue;
	return EXIT_SUCCESS;
}
//	Title:	Problem 100 - Arranged probability
//	URL:	https://projecteuler.net/problem=100
//	Input:	1000000000000
//	Output:	756872327473
//	Lang:	C++