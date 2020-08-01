#include <iostream>
#include <vector>
using namespace std;

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

inline vector<int> mulBig(vector<int> v, int base){
	int add = 0;
	for(int idx = 0; idx < v.size(); idx ++)
		v[idx] = v[idx] * base + add, add = v[idx] / 10, v[idx] %= 10;
	while(add)		v.push_back(add % 10), add /= 10;
	return v;
}

int main(){
	vector<int> numerator = {1}, denominator = {2};
	int inp, ans = 0;	cin >> inp;
	while(inp --){
		if(sumBig(numerator, denominator).size() > denominator.size())		ans ++;
		numerator = sumBig(numerator, mulBig(denominator, 2)), swap(numerator, denominator);
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 57 - Square root convergents
//	URL:	https://projecteuler.net/problem=57
//	Time:	O(?)
//	Input:	1000
//	Output:	153
//	Lang:	C++
