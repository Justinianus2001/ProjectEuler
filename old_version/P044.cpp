/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long val1, val2;
	for(long long idx1 = 2; ; idx1 ++)
		for(long long idx2 = 1; idx2 < idx1; idx2 ++){
			val1 = getPentagonalVal(idx1), val2 = getPentagonalVal(idx2);
			if(isPentagonalVal(val1 - val2) && isPentagonalVal(val1 + val2)){
				cout << val1 - val2;
				goto END;
			}
		}
	END:;
	return EXIT_SUCCESS;
}
//	Title:	Problem 44 - Pentagon numbers
//	URL:	https://projecteuler.net/problem=44
//	Input:
//	Output:	5482660
//	Lang:	C++