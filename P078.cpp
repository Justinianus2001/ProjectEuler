/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> p = {1};
	int inp;	cin >> inp;
	for(int n = 1; ; n ++){
		int sign = 0, k = 1, pN = 0;
		while(k <= n){
			pN = (pN + (sign ++ % 4 < 2 ? 1 : -1) * p[n - k]) % inp;
			int cur = (!(sign % 2)) ? sign / 2 + 1 : - sign / 2 - 1;
			k = cur * (cur * 3 - 1) / 2;
		}
		if(!pN){	cout << n;	break;	}
		p.push_back(pN);
	}
	return 0;
}
//	Title:	Problem 78 - Coin partitions
//	URL:	https://projecteuler.net/problem=78
//	Input:	1000000
//	Output:	55374
//	Lang:	C++
