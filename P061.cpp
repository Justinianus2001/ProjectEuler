/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

inline int getPolygonal(int num, int type){
	switch(type){
		case 3:		return num * (num + 1) / 2;
		case 4:		return num * num;
		case 5:		return num * (num * 3 - 1) / 2;
		case 6:		return num * (num * 2 - 1);
		case 7:		return num * (num * 5 - 3) / 2;
		case 8:		return num * (num * 3 - 2);
	}
	return -1;
}

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline long long mergeNum(long long lhs, long long rhs){
	return lhs * pow(10, log10(rhs)) + rhs;
}

map<int, vector<int>> mp[9];
map<int, bool> prevAns;
bool choose[9];

inline void find(vector<int> path, int start, int cur){
	if(path.size() == 6 && start == cur){
		path.push_back(path.front());
		int ans = 0;
		for(int idx = 1; idx < path.size(); idx ++)
			ans += mergeNum(path[idx - 1], path[idx]);
		if(!prevAns[ans])	cout << ans << '\n';
		prevAns[ans] = true;
	}
	else
		for(int type = 3; type < 9; type ++)
			if(!choose[type]){
				choose[type] = true;
				for(int num: mp[type][cur])
					path.push_back(num), find(path, start, num), path.pop_back();
				choose[type] = false;
			}
}

int main(){
	vector<int> polygonal[9];
	int inp, half;
	cin >> inp;		half = inp / 2;
	for(int idx = 1; getPolygonal(idx, 3) < pow(10, inp + 1); idx ++){
		if(log10(getPolygonal(idx, 3)) == inp)		polygonal[3].push_back(getPolygonal(idx, 3));
		if(log10(getPolygonal(idx, 4)) == inp)		polygonal[4].push_back(getPolygonal(idx, 4));
		if(log10(getPolygonal(idx, 5)) == inp)		polygonal[5].push_back(getPolygonal(idx, 5));
		if(log10(getPolygonal(idx, 6)) == inp)		polygonal[6].push_back(getPolygonal(idx, 6));
		if(log10(getPolygonal(idx, 7)) == inp)		polygonal[7].push_back(getPolygonal(idx, 7));
		if(log10(getPolygonal(idx, 8)) == inp)		polygonal[8].push_back(getPolygonal(idx, 8));
	}
	for(int type = 3; type < 9; type ++)
		for(int num: polygonal[type])
			mp[type][num / pow(10, half)].push_back(num % pow(10, half));
	for(int idx = pow(10, half - 1); idx < pow(10, half); idx ++)
		find({}, idx, idx);
	return 0;
}
//	Title:	Problem 61 - Cyclical figurate numbers
//	URL:	https://projecteuler.net/problem=61
//	Input:	4
//	Output:	28684
//	Lang:	C++
