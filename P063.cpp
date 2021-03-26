/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long maxBase, res = 0;
	cin >> maxBase;
	for(long long exp = 1; ; exp ++){
		bool haveNew = false;
		for(long long base = 1; base <= maxBase; base ++)
			if(bigInteger(base).pow(exp).getLog10() == exp)
				res ++, haveNew = true;
		if(!haveNew)	break;
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 63 - Powerful digit counts
//	URL:	https://projecteuler.net/problem=63
//	Input:	9
//	Output:	49
//	Lang:	C++