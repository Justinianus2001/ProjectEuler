/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <map>
using namespace std;

inline int sumDiv(int num){
	int sum = 1;
	for(int idx = 2; idx * idx <= num; idx ++)
		if(!(num % idx))	sum += (idx * idx == num ? idx : idx + num / idx);
	return sum;
}

int main(){
	map<int, int> mp;
	int inp, ans = 0;
	cin >> inp;
	for(int idx = 1; idx < inp; idx ++){
		mp[idx] = sumDiv(idx);
		if(mp[idx] < idx && mp[mp[idx]] == idx)		ans += idx + mp[idx];
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 21 - Amicable numbers
//	URL:	https://projecteuler.net/problem=21
//	Input:	10000
//	Output:	31626
//	Lang:	C++
