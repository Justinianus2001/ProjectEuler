/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long ans = 0;
	int inp;	cin >> inp;
	vector<int> phi(inp + 1);
	for(int deno = 2; deno <= inp; deno ++)
		phi[deno] = deno;
	for(int deno = 2; deno <= inp; deno ++){
		if(phi[deno] == deno){
			for(int mul = 1; deno * mul <= inp; mul ++)
				phi[deno * mul] -= phi[deno * mul] / deno;
		}
		ans += phi[deno];
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 72 - Counting fractions
//	URL:	https://projecteuler.net/problem=72
//	Input:	1000000
//	Output:	303963552391
//	Lang:	C++
