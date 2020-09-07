/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
	vector<int> num = {1};
	int inp, add = 0;
	cin >> inp;
	while(inp --){
		for(int idx = 0; idx < num.size(); idx ++){
			num[idx] = num[idx] * 2 + add, add = 0;
			while(num[idx] > 9)		num[idx] -= 10, add ++;
		}
		if(add)		num.push_back(add), add = 0;
	}
	cout << accumulate(begin(num), end(num), 0);
	return 0;
}
//	Title:	Problem 16 - Power digit sum
//	URL:	https://projecteuler.net/problem=16
//	Input:	1000
//	Output:	1366
//	Lang:	C++
