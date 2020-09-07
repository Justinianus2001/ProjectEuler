/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
using namespace std;

bool isComposite[1000001];

inline void sieve(int num){
	isComposite[0] = isComposite[1] = true;
	for(int idx1 = 2; idx1 * idx1 <= num; idx1 += (idx1 != 2) + 1)
		if(!isComposite[idx1])
			for(int idx2 = idx1 * idx1; idx2 <= num; idx2 += idx1)
				isComposite[idx2] = true;
}

int main(){
	vector<int> primes;
	int inp, cnt = 0, maxLen = 0, val, ans = 0;
	cin >> inp;		sieve(inp);
	for(int idx = 0; idx < inp; idx ++)
		if(!isComposite[idx])		primes.push_back(idx);
	for(int base = 0; base < primes.size() - maxLen; base ++){
		val = 0;
		for(int cur = base; val + primes[cur] < inp; cur ++){
			val += primes[cur];
			if(!isComposite[val] && cur - base + 1 > maxLen)		maxLen = cur - base + 1, ans = val;
		}
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 50 - Consecutive prime sum
//	URL:	https://projecteuler.net/problem=50
//	Input:	1000000
//	Output:	997651
//	Lang:	C++
