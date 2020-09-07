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

inline vector<int> sumBig(vector<int> num1, vector<int> num2){
	if(num1.size() < num2.size())	swap(num1, num2);
	int add = 0;
	for(int idx = 0; idx < num1.size(); idx ++){
		num1[idx] += (idx < num2.size() ? num2[idx] : 0) + add, add = 0;
		if(num1[idx] > 9)	num1[idx] -= 10, add = 1;
	}
	if(add)		num1.push_back(1);
	return num1;
}

int main(){
	vector<int> numerator = {2},
				denominator = {1};
	int inp;	cin >> inp;
	for(int idx = 2; idx <= inp; idx ++){
		int a = (!(idx % 3) ? (idx / 3) * 2 : 1);
		vector<int> temp = denominator;
		denominator = numerator,
		numerator = sumBig(mulBig(denominator, a), temp);
	}
	cout << accumulate(begin(numerator), end(numerator), 0);
	return 0;
}
//	Title:	Problem 65 - Convergents of e
//	URL:	https://projecteuler.net/problem=65
//	Input:	100
//	Output:	272
//	Lang:	C++
