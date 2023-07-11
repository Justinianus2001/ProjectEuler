/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long inp, sumFact, num, res = 0, *fact = new long long[10]();
	fact[0] = fact[1] = 1;
	for(long long num = 2; num < 10; num ++)
		fact[num] = fact[num - 1] * num;
	cin >> inp;		inp *= fact[9];
	for(long long idx = 3; idx <= inp; idx ++){
		sumFact = 0, num = idx;
		while(num)	sumFact += fact[num % 10], num /= 10;
		if(sumFact == idx)	res += sumFact;
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 34 - Digit factorials
//	URL:	https://projecteuler.net/problem=34
//	Input:	8 (8 * 9!)
//	Output:	40730
//	Lang:	C++
