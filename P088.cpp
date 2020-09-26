/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <numeric>
#include <set>
using namespace std;

int inp, mp[100000];

inline void getAllValidK(int num, int div, int mul, int sum, int turn){
	if(mul == 1){
		mp[turn + sum] = min(mp[turn + sum], num);
		return;
	}else if(div == num || div > min(mul, sum) || turn > inp){
		return;
	}else if(!(mul % div)){
		getAllValidK(num, div, mul / div, sum - div, turn + 1);
	}
	getAllValidK(num, div + 1, mul, sum, turn);
}

int main(){
	set<int> s;		cin >> inp;
	fill(mp, mp + inp + 1, inp * 2);
	for(int num = 4; num <= inp * 2; num ++)
		getAllValidK(num, 2, num, num, 0);
	for(int idx = 2; idx <= inp; idx ++)
		s.insert(mp[idx]);
	cout << accumulate(begin(s), end(s), 0);
	return 0;
}
//	Title:	Problem 88 - Product-sum numbers
//	URL:	https://projecteuler.net/problem=88
//	Input:	12000
//	Output:	7587457
//	Lang:	C++
