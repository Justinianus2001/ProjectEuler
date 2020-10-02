/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline void findAll(vector<vector<int>> form, int num, int cur, int numDices, vector<int> &sqrNum){
	if(cur == numDices){
		vector<int>::iterator it = find(begin(sqrNum), end(sqrNum), num);
		if(it != end(sqrNum))
			sqrNum.erase(it);
	}
	else{
		for(int idx = 0; idx < form[cur].size(); idx ++)
			if(form[cur][idx] == 6 || form[cur][idx] == 9)
					findAll(form, num * 10 + 6, cur + 1, numDices, sqrNum),
					findAll(form, num * 10 + 9, cur + 1, numDices, sqrNum);
			else	findAll(form, num * 10 + form[cur][idx], cur + 1, numDices, sqrNum);
	}
}

int main(){
	vector<int> sqrNum;
	int diceSides[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		numDices, ans = 0, chooseIdx[100] = {};
	cin >> numDices;
	for(int num = 1; num * num < pow(10, numDices); num ++)
		sqrNum.push_back(num * num);
	vector<vector<int>> diceLst;
	for(int sub = 0; sub < 1 << 10; sub ++){
		vector<int> dice;
		for(int idx = 0; idx < 10; idx ++)
			if(sub >> idx & 1)	dice.push_back(diceSides[idx]);
		if(dice.size() == 6)	diceLst.push_back(dice);
	}
	while(true){
		vector<vector<int>> form;
		for(int idx = 0; idx < numDices; idx ++)
			form.push_back(diceLst[chooseIdx[idx]]);
		vector<int> copy = sqrNum;
		do	findAll(form, 0, 0, numDices, copy);
		while(next_permutation(begin(form), end(form)));
		if(!copy.size())	ans ++;
		int prev = numDices - 1;
		chooseIdx[prev] ++;
		while(chooseIdx[prev] == diceLst.size())
			if(!prev)	goto END;
			else		chooseIdx[prev] = 0, chooseIdx[-- prev] ++;
	}
	END:;
	cout << ans;
	return 0;
}
//	Title:	Problem 90 - Cube digit pairs
//	URL:	https://projecteuler.net/problem=90
//	Input:	2
//	Output:	1217
//	Lang:	C++
