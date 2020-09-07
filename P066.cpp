/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

inline vector<int> toBig(int num){
	vector<int> ans;
	while(num)	ans.push_back(num % 10), num /= 10;
	return ans;
}

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

inline vector<int> mulBigAdv(vector<int> num, vector<int> base){
	vector<int> add = {0};
	for(int idx = 0; idx < num.size(); idx ++){
		vector<int> cur = sumBig(mulBig(base, num[idx]), add);
		num[idx] = cur.front(), cur.erase(begin(cur)), add = cur;
	}
	while(add.size())	num.push_back(add.front()), add.erase(begin(add));
	return num;
}

inline bool greaterBig(vector<int> lhs, vector<int> rhs){
	if(lhs.size() > rhs.size())		return true;
	if(lhs.size() < rhs.size())		return false;
	for(int idx = 0; idx < lhs.size(); idx ++){
		if(lhs[idx] > rhs[idx])		return true;
		if(lhs[idx] < rhs[idx])		return false;
	}
	return false;
}

int main(){
	vector<int> maxX = {0};
	int inp, maxD = -1;
	cin >> inp;
	for(int D = 2; D <= inp; D ++){
		int sqrtD = sqrt(D);
		if(sqrtD * sqrtD == D)	continue;
		int a = sqrtD,
			numerator = 0,
			denominator = 1;
		vector<int> x[] = {{0}, {1}, toBig(a)},
					y[] = {{0}, {0}, {1}};
		while(true){
			numerator = denominator * a - numerator,
			denominator = (D - numerator * numerator) / denominator,
			a = (sqrtD + numerator) / denominator,
			x[0] = x[1], x[1] = x[2], x[2] = sumBig(mulBig(x[1], a), x[0]),
			y[0] = y[1], y[1] = y[2], y[2] = sumBig(mulBig(y[1], a), y[0]);
			vector<int> lhs = mulBigAdv(x[2], x[2]),
						rhs = sumBig(mulBig(mulBigAdv(y[2], y[2]), D), toBig(1));
			if(lhs == rhs)		break;
		}
		if(greaterBig(x[2], maxX))
			maxX = x[2], maxD = D;
	}
	cout << maxD;
	return 0;
}
//	Title:	Problem 66 - Diophantine equation
//	URL:	https://projecteuler.net/problem=66
//	Input:	1000
//	Output:	661
//	Lang:	C++
