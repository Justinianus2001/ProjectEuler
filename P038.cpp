/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

inline bool isPandigital(long long val, long long num){
	long long mp[num + 1] = {};
	while(val)
		if(val % 10 > num || mp[val % 10] ++ || !(val % 10))		return false;
		else val /= 10;
	return true;
}

int main(int argc, char** argv){
	long long digits, len, val, res = 0;
	cin >> digits;
	for(long long base = 1; base < pow(10LL, digits / 2); base ++){
		len = val = 0;
		for(long long mul = 1; len < digits; mul ++)
			val = val * pow(10LL, log10(base * mul)) + base * mul, len += log10(base * mul);
		if(len == digits && isPandigital(val, digits))		res = max(res, val), cout << val << '\n';
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 38 - Pandigital multiples
//	URL:	https://projecteuler.net/problem=38
//	Input:	9
//	Output:	932718654
//	Lang:	C++