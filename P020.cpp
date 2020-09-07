/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
	vector<int> ans = {1};
	int inp;
	cin >> inp;
	for(int idx1 = 2; idx1 <= inp; idx1 ++){
		int add = 0;
		for(int idx2 = 0; idx2 < ans.size(); idx2 ++){
			ans[idx2] = ans[idx2] * idx1 + add, add = 0;
			if(ans[idx2] > 9)	add += ans[idx2] / 10, ans[idx2] %= 10;
		}
		while(add)	ans.push_back(add % 10), add /= 10;
	}
	cout << accumulate(begin(ans), end(ans), 0);
	return 0;
}
//	Title:	Problem 20 - Factorial digit sum
//	URL:	https://projecteuler.net/problem=20
//	Input:	100
//	Output:	648
//	Lang:	C++
