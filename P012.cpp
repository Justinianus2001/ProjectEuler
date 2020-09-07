/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline int sumDiv(int num){
	int sum = 0;
	for(int idx = 1; idx * idx <= num; idx ++)
		if(!(num % idx))	sum += (idx * idx == num ? 1 : 2);
	return sum;
}

int main(){
	long long num = 0;
	int inp;		cin >> inp;
	for(int idx = 1; ; idx ++){
		num += idx;
		if(sumDiv(num) >= inp)	break;
	}
	cout << num;
	return 0;
}
//	Title:	Problem 12 - Highly divisible triangular number
//	URL:	https://projecteuler.net/problem=12
//	Input:	500
//	Output:	76576500
//	Lang:	C++
