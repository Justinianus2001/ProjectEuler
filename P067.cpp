/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P067.txt", "r", stdin);
	vector<long long> cur, next;
	long long *arr;
	for(long long row = 1; ; row ++){
		arr = new long long[row],
		next.clear();
		for(int col = 0; col < row; col ++){
			if(!(cin >> arr[col]))		goto END;
			next.push_back(max((col ? cur[col - 1] : 0), (col != cur.size() ? cur[col] : 0)) + arr[col]);
		}
		cur = next;
	}
	END:;
	cout << *max_element(begin(cur), end(cur));
	return EXIT_SUCCESS;
}
//	Title:	Problem 67 - Maximum path sum II
//	URL:	https://projecteuler.net/problem=67
//	Input:	P067.txt
//	Output:	7273
//	Lang:	C++
