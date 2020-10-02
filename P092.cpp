/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <map>
using namespace std;

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

int mp[10000000];

inline int getSqrDigitSum(int num){
	int ans = 0;
	while(num)	ans += pow(num % 10, 2), num /= 10;
	return ans;
}

inline int getChain(int num){
	if(mp[num])		return mp[num];
	return mp[num] = getChain(getSqrDigitSum(num));
}

int main(){
	int inp, ans = 0;
	cin >> inp;
	mp[89] = 89, mp[1] = 1;
	for(int start = 2; start < inp; start ++)
		if(getChain(start) == 89)	ans ++;
	cout << ans;
	return 0;
}
//	Title:	Problem 92 - Square digit chains
//	URL:	https://projecteuler.net/problem=92
//	Input:	10000000
//	Output:	8581146
//	Lang:	C++
