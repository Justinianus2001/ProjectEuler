/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
using namespace std;

inline bool isAbundant(int num){
	int sum = 1;
	for(int idx = 2; idx * idx <= num; idx ++)
		if(!(num % idx))	sum += (idx * idx == num ? idx : idx + num / idx);
	return sum > num;
}

int main(){
	vector<int> v;
	bool mp[300000] = {};
	long long inp, ans;
	cin >> inp;
	ans = inp * (inp + 1) / 2;
	for(int idx = 1; idx <= inp; idx ++)
		if(isAbundant(idx)){
			v.push_back(idx);
			for(int val: v)
				if(idx + val <= inp){
					if(!mp[idx + val])	ans -= idx + val;
					mp[idx + val] = true;
				} else break;
		}
	cout << ans;
	return 0;
}
//	Title:	Problem 23 - Non-abundant sums
//	URL:	https://projecteuler.net/problem=23
//	Input:	28123
//	Output:	4179871
//	Lang:	C++
