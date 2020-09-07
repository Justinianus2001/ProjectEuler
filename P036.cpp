/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline bool isPalindrome(string num){
	for(int idx = 0; idx < num.length() / 2; idx ++)
		if(num[idx] != num[num.length() - idx - 1])		return false;
	return true;
}

inline string convert(int num, int base){
	string ans;
	do ans.insert(0, 1, (char)((num % base) + '0')), num /= base;
	while(num);
	return ans;
}

int main(){
	int inp, ans = 0;	cin >> inp;
	for(int idx = 1; idx < inp; idx ++)
		if(isPalindrome(convert(idx, 2)) && isPalindrome(convert(idx, 10)))		ans += idx;
	cout << ans;
	return 0;
}
//	Title:	Problem 36 - Double-base palindromes
//	URL:	https://projecteuler.net/problem=36
//	Input:	1000000
//	Output:	872187
//	Lang:	C++
