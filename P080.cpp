/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

inline bool equalSmall(int intL, vector<int> decL, int intR, vector<int> decR, int decDigit){
	if(intL != intR)	return false;
	for(int idx = 0; idx < decDigit; idx ++)
		if(decL[idx] != decR[idx])	return false;
	return true;
}

inline void sumSmall(int intL, vector<int> decL, int intR, vector<int> decR, int &intAns, vector<int> &decAns){
	while(decL.size() < decR.size())	decL.push_back(0);
	while(decL.size() > decR.size())	decR.push_back(0);
	int add = 0;
	for(int idx = decL.size() - 1; idx >= 0; idx --){
		decAns[idx] = decL[idx] + decR[idx] + add, add = 0;
		if(decAns[idx] > 9)		decAns[idx] %= 10, add = 1;
	}
	intAns = intL + intR + add;
}

inline void divSmall(int &intAns, vector<int> &decAns, int div){
	int add = intAns % div;
	intAns /= div;
	for(int idx = 0; idx < decAns.size(); idx ++){
		int nextAdd = (add * 10 + decAns[idx]) % div;
		decAns[idx] = (add * 10 + decAns[idx]) / div, add = nextAdd;
	}
}

inline vector<int> toBig(int num){
	vector<int> ans;
	while(num)	ans.push_back(num % 10), num /= 10;
	reverse(begin(ans), end(ans));
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
	vector<int> add = {};
	for(int idx = 0; idx < num.size(); idx ++){
		vector<int> cur = sumBig(mulBig(base, num[idx]), add);
		num[idx] = cur.front(), cur.erase(begin(cur)), add = cur;
	}
	while(add.size())	num.push_back(add.front()), add.erase(begin(add));
	return num;
}

inline void mulSmall(int intL, vector<int> decL, int intR, vector<int> decR, int &intAns, vector<int> &decAns, int ansDecDigit){
	int decDigit = decL.size() + decR.size();
	vector<int> lhs = toBig(intL), rhs = toBig(intR);
	for(auto dec: decL)		lhs.push_back(dec);
	for(auto dec: decR)		rhs.push_back(dec);
	reverse(begin(lhs), end(lhs)), reverse(begin(rhs), end(rhs));
	vector<int> ans = mulBigAdv(lhs, rhs);
	reverse(begin(ans), end(ans));
	intAns = 0;
	while(!ans[0])	ans.erase(begin(ans));
	for(int idx = 0; idx < ans.size() - decDigit; idx ++)
		intAns = intAns * 10 + ans[idx];
	ans.erase(begin(ans), begin(ans) + ans.size() - decDigit);
	decAns = ans;
	while(decAns.size() > ansDecDigit)		decAns.pop_back();
	while(decAns.size() < ansDecDigit)		decAns.push_back(0);
}

inline bool greaterOrEqualSmall(int intL, vector<int> decL, int intR, vector<int> decR){
	if(intL > intR)		return true;
	if(intL < intR)		return false;
	for(int idx = 0; idx < decL.size(); idx ++){
		if(decL[idx] > decR[idx])	return true;
		if(decL[idx] < decR[idx])	return false;
	}
	return true;
}

int main(){
	int inp, decDigit, ans = 0;
	cin >> inp >> decDigit;		decDigit += 3;
	for(int num = 2; num <= inp; num ++){
		if((int)sqrt(num) * (int)sqrt(num) == num)		continue;
		vector<int> decL(decDigit), decR(decDigit), decCur(decDigit);
		int intL = 1, intR = num;
		while(!equalSmall(intL, decL, intR, decR, decDigit - 2)){
			vector<int> decM(decDigit), decM2;
			int intM, intM2;
			sumSmall(intL, decL, intR, decR, intM, decM);
			divSmall(intM, decM, 2);
			mulSmall(intM, decM, intM, decM, intM2, decM2, decDigit);
			if(greaterOrEqualSmall(intM2, decM2, num, decCur))
				intR = intM, decR = decM;
			else	intL = intM, decL = decM;
		}
		vector<int> intAns = toBig(intL), decAns = decL;
		int cnt = decDigit - 3;
		while(cnt && intAns.size())		ans += intAns[0], intAns.erase(begin(intAns)), cnt --;
		while(cnt && decAns.size())		ans += decAns[0], decAns.erase(begin(decAns)), cnt --;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 80 - Square root digital expansion
//	URL:	https://projecteuler.net/problem=80
//	Input:	100 100
//	Output:	40886
//	Lang:	C++
