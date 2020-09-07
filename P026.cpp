/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <map>
using namespace std;

int main(){
	int inp, ans, maxCycle = 0, remain, cnt;
	cin >> inp;
	for(int idx = 2; idx < inp; idx ++){
		map<int, int> mp;
		remain = 1, cnt = 1;
		while(true){
			if(!(remain % idx))		goto NEXT;
			remain %= idx;
			if(mp[remain])			break;
			mp[remain] = cnt;
			while(remain < idx)		cnt ++, remain *= 10;
		}
		if(cnt - mp[remain] > maxCycle)		ans = idx, maxCycle = cnt - mp[remain];
		NEXT:;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 26 - Reciprocal cycles
//	URL:	https://projecteuler.net/problem=26
//	Input:	1000
//	Output:	983
//	Lang:	C++
