/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <algorithm>
#include <iostream>
#include <map>
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

inline bool isPrime(int num){
	if(num == 2 || num == 3)			return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

int main(){
	map<int, bool> mp;
	int n;		cin >> n;
	for(int idx = pow(10, n - 1) + 1; idx < pow(10, n); idx += 2)
		if(isPrime(idx) && !mp[idx]){
			vector<int> lst = {idx};
			string str = to_string(idx);
			while(next_permutation(begin(str), end(str)))
				if(isPrime(stoi(str)))	lst.push_back(stoi(str));
			sort(begin(lst), end(lst));
			for(int prime1 = 0; prime1 < lst.size(); prime1 ++)
				for(int prime2 = prime1 + 1; prime2 < lst.size(); prime2 ++)
					for(int prime3 = prime2 + 1; prime3 < lst.size(); prime3 ++)
						if(lst[prime3] - lst[prime2] == lst[prime2] - lst[prime1]){
							cout << lst[prime1] << lst[prime2] << lst[prime3] << '\n';
							goto END;
						}
			END:;
			for(int val: lst)	mp[val] = true;
		}
	return 0;
}
//	Title:	Problem 49 - Prime permutations
//	URL:	https://projecteuler.net/problem=49
//	Input:	4
//	Output:	148748178147
//		296962999629
//	Lang:	C++
