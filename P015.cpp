/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long size, paths = 1;
	cin >> size;
	for(long long grid = 0; grid < size; grid ++)
		paths = paths * (size * 2 - grid) / (grid + 1);
	cout << paths;
	return EXIT_SUCCESS;
}
//	Title:	Problem 15 - Lattice paths
//	URL:	https://projecteuler.net/problem=15
//	Input:	20
//	Output:	137846528820
//	Lang:	C++
