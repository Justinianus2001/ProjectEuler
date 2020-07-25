#include <iostream>
#include <vector>
using namespace std;

inline vector<int> powBig(int base, int exp, int digit){
	vector<int> v = {1};
	int add;
	while(exp --){
		add = 0;
		for(int idx = 0; idx < v.size(); idx ++)
			v[idx] = v[idx] * base + add, add = v[idx] / 10, v[idx] %= 10;
		while(add && v.size() < digit)	v.push_back(add % 10), add /= 10;
	}
	return v;
}

inline vector<int> sumBig(vector<int> num1, vector<int> num2, int digit){
	if(num1.size() < num2.size())	swap(num1, num2);
	int add = 0;
	for(int idx = 0; idx < num1.size(); idx ++){
		num1[idx] += (idx < num2.size() ? num2[idx] : 0) + add, add = 0;
		if(num1[idx] > 9)	num1[idx] -= 10, add = 1;
	}
	if(add && num1.size() < digit)		num1.push_back(1);
	return num1;
}

int main(){
	vector<int> ans = {0};
	int inp, digit;		cin >> inp >> digit;
	for(int idx = 1; idx <= inp; idx ++)
		ans = sumBig(ans, powBig(idx, idx, digit), digit);
	for(int idx = ans.size() - 1; idx >= 0; idx --)
		cout << ans[idx];
	return 0;
}
//	Title:	Problem 48 - Self powers
//	URL:	https://projecteuler.net/problem=48
//	Time:	O(?)
//	Input:	1000 10
//	Output:	9110846700
//	Lang:	C++
