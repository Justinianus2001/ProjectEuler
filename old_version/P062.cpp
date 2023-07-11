/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	map<string, pair<long long, long long>> mp;
	long long perm;		cin >> perm;
	for(long long idx = 1; ; idx ++){
		string strNum = to_string(getCubeVal(idx));
		sort(begin(strNum), end(strNum));
		if(!mp[strNum].second)
			mp[strNum].second = getCubeVal(idx);
		if(++ mp[strNum].first == perm){
			cout << mp[strNum].second;
			break;
		}
	}
	return EXIT_SUCCESS;
}
//	Title:	Problem 62 - Cubic permutations
//	URL:	https://projecteuler.net/problem=62
//	Input:	5
//	Output:	127035954683
//	Lang:	C++