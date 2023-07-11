/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = -1, maxChain = 0;
	cin >> range;	sieveSumDiv(range);
	bool *ok = new bool[range + 1]();
	for(long long num = 2; num <= range; num ++)
		if(!ok[num]){
			vector<long long> chains = {num};
			while(true){
				if(mapSumDiv[chains.back()] == 1 || mapSumDiv[chains.back()] > range)
					goto END;
				vector<long long>::iterator findNext = find(begin(chains), end(chains), mapSumDiv[chains.back()]);
				if(findNext != end(chains)){
					chains.erase(begin(chains), findNext);
					break;
				}
				chains.push_back(mapSumDiv[chains.back()]),
				ok[chains.back()] = true;
			}
			if(chains.size() > maxChain)
				sort(begin(chains), end(chains)),
				maxChain = chains.size(),
				res = chains[0];
			END:;
		}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 95 - Amicable chains
//	URL:	https://projecteuler.net/problem=95
//	Input:	1000000
//	Output:	14316
//	Lang:	C++