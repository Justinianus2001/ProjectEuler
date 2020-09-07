/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline bool isPandigital(int val, int num){
	int mp[num + 1] = {};
	while(val)
		if(val % 10 > num || mp[val % 10] ++ || !(val % 10))		return false;
		else val /= 10;
	return true;
}

int main(){
	int inp, length, val, ans = 0;
	cin >> inp;
	for(int idx1 = 1; idx1 < pow(10, inp / 2); idx1 ++){
		length = 0, val = 0;
		for(int idx2 = 1; length < inp; idx2 ++)
			val = val * pow(10, log10(idx1 * idx2)) + idx1 * idx2, length += log10(idx1 * idx2);
		if(length == inp && isPandigital(val, inp))		ans = max(ans, val);
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 38 - Pandigital multiples
//	URL:	https://projecteuler.net/problem=38
//	Input:	9
//	Output:	932718654
//	Lang:	C++
