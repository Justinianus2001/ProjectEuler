/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

int main(){
	int inp, cnt, maxCnt = 0, ans = 0;
	long long num;
	cin >> inp;
	for(int idx = 2; idx < inp; idx ++){
		cnt = 0, num = idx;
		while(num != 1){
			cnt ++;
			if(num & 1)		num = num * 3 + 1;
			else			num /= 2;
		}
		if(cnt > maxCnt)	ans = idx, maxCnt = cnt;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 14 - Longest Collatz sequence
//	URL:	https://projecteuler.net/problem=14
//	Input:	1000000
//	Output:	837799
//	Lang:	C++
