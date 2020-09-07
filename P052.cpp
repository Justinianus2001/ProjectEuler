/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <algorithm>
using namespace std;

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline bool compare(int lhs, int rhs){
	string left = to_string(lhs), right = to_string(rhs);
	sort(begin(left), end(left)), sort(begin(right), end(right));
	return left == right;
}

int main(){
	int inp, ok = 0;	cin >> inp;
	for(int num = 1; ; num ++){
		if(log10(num) != log10(num * inp))		continue;
		ok = 1;
		for(int mul = 2; mul <= inp; mul ++)
			if(!compare(num, num * mul)){		ok = 0;	break;		}
		if(ok){		cout << num;	break;		}
	}
	END:;
	return 0;
}
//	Title:	Problem 52 - Permuted multiples
//	URL:	https://projecteuler.net/problem=52
//	Input:	6
//	Output:	142857
//	Lang:	C++
