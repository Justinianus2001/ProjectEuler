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
	int inp, cnt = 0, idx = 2;
	cin >> inp;
	while(true){
		cnt += isPrime(idx);
		if(cnt == inp)		break;
		idx ++;
	}
	cout << idx;
	return 0;
}
//	Title:	Problem 7 - 10001st prime
//	URL:	https://projecteuler.net/problem=7
//	Input:	10001
//	Output:	104743
//	Lang:	C++
