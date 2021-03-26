/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	vector<long long> p = {1};
	long long div;	cin >> div;
	for(long long n = 1; ; n ++){
		long long sign = 0, k = 1, pN = 0;
		while(k <= n){
			pN = (pN + (sign ++ % 4 < 2 ? 1 : -1) * p[n - k]) % div;
			long long cur = !(sign % 2) ? sign / 2 + 1 : - sign / 2 - 1;
			k = cur * (cur * 3 - 1) / 2;
		}
		if(!pN){	cout << n;	break;	}
		p.push_back(pN);
	}
	return EXIT_SUCCESS;
}
//	Title:	Problem 78 - Coin partitions
//	URL:	https://projecteuler.net/problem=78
//	Input:	1000000
//	Output:	55374
//	Lang:	C++