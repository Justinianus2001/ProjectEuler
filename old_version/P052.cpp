/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range;	cin >> range;
	for(long long num = 1; ; num ++){
		if(log10(num) != log10(num * range))		continue;
		bool ok = true;
		for(long long mul = 2; mul <= range; mul ++)
			if(!isPermutation(num, num * mul)){	ok = false;	break;	}
		if(ok){	cout << num;	break;	}
	}
	return EXIT_SUCCESS;
}
//	Title:	Problem 52 - Permuted multiples
//	URL:	https://projecteuler.net/problem=52
//	Input:	6
//	Output:	142857
//	Lang:	C++