/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

inline vector<int> mulBig(vector<int> v, int base){
	int add = 0;
	for(int idx = 0; idx < v.size(); idx ++)
		v[idx] = v[idx] * base + add, add = v[idx] / 10, v[idx] %= 10;
	while(add)		v.push_back(add % 10), add /= 10;
	return v;
}

int main(){
	int inp, ans = 0;	cin >> inp;
	for(int base = 1; base < inp; base ++){
		vector<int> num = {1};
		for(int exp = 1; exp < inp; exp ++)
			num = mulBig(num, base), ans = max(ans, accumulate(begin(num), end(num), 0));
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 56 - Powerful digit sum
//	URL:	https://projecteuler.net/problem=56
//	Input:	100
//	Output:	972
//	Lang:	C++
