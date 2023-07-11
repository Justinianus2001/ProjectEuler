/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;	cin >> range;
	long long *minExp = new long long[(range + 1) * 16](),
			  *base = new long long[range + 1]();
	for(long long num = 1; pow(2LL, num) <= range; num ++)
		for(long long exp = 1; exp <= range; exp ++)
			if(!minExp[num * exp])
				minExp[num * exp] = num;
	for(long long num = 2; num <= range; num ++)
		if(!base[num]){
			long long numPow = num * num;
			while(numPow <= range)
				base[numPow] = num, numPow *= num;
		}
		else{
			long long mul = 1, cnt = 0;
			while(mul < num)
				mul *= base[num], cnt ++;
			for(long long exp = 2; exp <= range; exp ++)
				if(minExp[exp * cnt] < cnt)
					res ++;
		}
	cout << (range - 1) * (range - 1) - res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 29 - Distinct powers
//	URL:	https://projecteuler.net/problem=29
//	Input:	100
//	Output:	9183
//	Lang:	C++
