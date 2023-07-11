/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long start;		cin >> start;
	for(long long idx1 = start + 1, idx2 = start + 1, idx3 = start + 1; ; idx3 ++){
		while(getTriangularVal(idx1) < getHexagonalVal(idx3))	idx1 ++;
		while(getPentagonalVal(idx2) < getHexagonalVal(idx3))	idx2 ++;
		if(getTriangularVal(idx1) == getPentagonalVal(idx2) && getPentagonalVal(idx2) == getHexagonalVal(idx3)){
			cout << getHexagonalVal(idx3);	break;
		}
	}
	return EXIT_SUCCESS;
}
//	Title:	Problem 45 - Triangular, pentagonal, and hexagonal
//	URL:	https://projecteuler.net/problem=45
//	Input:	143
//	Output:	1533776805
//	Lang:	C++