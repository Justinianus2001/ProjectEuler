/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline bool isPrime(int num){
	if(num == 2 || num == 3)			return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

int main(){
	int inp, ans = 1;
	cin >> inp;
	for(int num = 2; ; num ++)
		if(isPrime(num)){
			if(ans * num > inp)		break;
			ans *= num;
		}
	cout << ans;
	return 0;
}
//	Title:	Problem 69 - Totient maximum
//	URL:	https://projecteuler.net/problem=69
//	Input:	1000000
//	Output:	510510
//	Lang:	C++
