#include <iostream>
#include <algorithm>
using namespace std;

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline int compare(int lhs, int rhs){
	string l = to_string(lhs), r = to_string(rhs);
	sort(begin(l), end(l)), sort(begin(r), end(r));
	return l == r;
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
//	Time:	O(?)
//	Input:	6
//	Output:	142857
//	Lang:	C++