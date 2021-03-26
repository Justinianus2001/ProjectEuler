/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	vector<long long> row;
	long long maxN, goal, res = 0, *isFull;
	cin >> maxN >> goal;
	isFull = new long long[maxN]();
	for(long long step = 0; step <= maxN; step ++){
		for(long long col = row.size() - 1; col > 0; col --){
			if(isFull[col])	continue;
			row[col] += row[col - 1];
			if(row[col] > goal)
				row[col] = goal + 1, res += maxN - step + 1, isFull[col] = true;
		}
		row.push_back(1);
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 53 - Combinatoric selections
//	URL:	https://projecteuler.net/problem=53
//	Input:	100 1000000
//	Output:	4075
//	Lang:	C++