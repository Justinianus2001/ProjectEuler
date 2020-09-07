/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("P067.txt", "r", stdin);
	vector<int> cur;
	int inp[10000];
	for(int row = 1; ; row ++){
		if(!(cin >> inp[0]))	break;
		vector<int> next;
		for(int col = 1; col < row; col ++)
			cin >> inp[col];
		for(int col = 0; col < row; col ++)
			next.push_back(max((col ? cur[col - 1] : 0), (col != cur.size() ? cur[col] : 0)) + inp[col]);
		cur = next;
	}
	cout << *max_element(begin(cur), end(cur));
	return 0;
}
//	Title:	Problem 67 - Maximum path sum II
//	URL:	https://projecteuler.net/problem=67
//	Input:	P067.txt
//	Output:	7273
//	Lang:	C++
