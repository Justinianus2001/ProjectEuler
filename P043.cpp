/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string str;
	bool check;
	int inp, prime[] = {0, 2, 3, 5, 7, 11, 13, 17};
	long long num, ans = 0;
	cin >> inp;
	for(int idx = 0; idx <= inp; idx ++)
		str += (char)(idx + '0');
	do{
		check = true;
		for(int idx = 1; idx < str.length() - 2; idx ++){
			num = stoll(str.substr(idx, 3));
			if(num % prime[idx]){	check = false;	break;	}
		}
		if(check)	num = stoll(str), ans += num;
	}
	while(next_permutation(begin(str), end(str)));
	cout << ans;
	return 0;
}
//	Title:	Problem 43 - Sub-string divisibility
//	URL:	https://projecteuler.net/problem=43
//	Input:	9
//	Output:	16695334890
//	Lang:	C++
