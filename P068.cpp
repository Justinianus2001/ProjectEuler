/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

inline bool greaterStr(string lhs, string rhs){
	if(lhs.length() < rhs.length())		return false;
	if(lhs.length() > rhs.length())		return true;
	for(int idx = 0; idx < lhs.length(); idx ++){
		if(lhs[idx] < rhs[idx])		return false;
		if(lhs[idx] > rhs[idx])		return true;
	}
	return false;
}

int main(){
	int numGon, numDigit,
		core[10000],
		edge[10000];
	string ans;		cin >> numGon >> numDigit;
	vector<int> v;
	for(int num = 1; num <= numGon * 2; num ++)
		v.push_back(num);
	do{
		string cur;
		int mn, start = 0, sum;
		for(int idx = 0; idx < numGon * 2; idx ++)
			if(idx < numGon)	core[idx] = v[idx];
			else			edge[idx - numGon] = v[idx];
		sum = edge[0] + core[0] + core[1], mn = edge[0];
		for(int idx = 1; idx < numGon; idx ++){
			if(edge[idx] + core[idx] + core[(idx + 1) % numGon] != sum)		goto END;
			if(edge[idx] < mn)		mn = edge[idx], start = idx;
		}
		for(int idx = start; idx < numGon; idx ++)
			cur += to_string(edge[idx]) + to_string(core[idx])
				+ to_string(core[(idx + 1) % numGon]);
		for(int idx = 0; idx < start; idx ++)
			cur += to_string(edge[idx]) + to_string(core[idx])
				+ to_string(core[(idx + 1) % numGon]);
		if(cur.length() == numDigit && greaterStr(cur, ans))	ans = cur;
		END:;
	}while(next_permutation(begin(v), end(v)));
	cout << ans;
	return 0;
}
//	Title:	Problem 68 - Magic 5-gon ring
//	URL:	https://projecteuler.net/problem=68
//	Input:	5 16
//	Output:	6531031914842725
//	Lang:	C++
