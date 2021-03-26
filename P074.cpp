/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long fact[10],
		range, chain, res = 0;
	for(long long num = 0; num < 10; num ++)
		fact[num] = getFact(num);
	cin >> range >> chain;
	long long *cache = new long long[range + 1]();
	cache[169] = cache[363601] = cache[1454] = 3;
	cache[871] = cache[45361] = 2;
	cache[872] = cache[45362] = 2;
	for(long long num = 1; num < range; num ++){
		long long cnt = 0, temp = num;
		vector<long long> seq = {0};
		while(seq.back() != temp){
			seq.push_back(temp);
			temp = sumFactDigit(temp);
			cnt ++;
			if(temp < range && cache[temp]){
				cnt += cache[temp];
				break;
			}
		}
		res += (cnt == chain);
		for(long long idx = 1; idx < seq.size(); idx ++){
			if(seq[idx] < range)
				cache[seq[idx]] = cnt;
			cnt --;
		}
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 74 - Digit factorial chains
//	URL:	https://projecteuler.net/problem=74
//	Input:	1000000 60
//	Output:	402
//	Lang:	C++