/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long width;	cin >> width;
	long long res = width * width * 3;
	for(long long x = 1; x <= width; x ++){
		res += min(width - x, x) * 2;
		for(long long y = 1; y < x; y ++){
			long long cntXPos = x / __gcd(x, y),
					cntYPos = y / __gcd(x, y);
			res += min((width - y) / cntXPos, x / cntYPos) * 2;
			res += min(y / cntXPos, (width - x) / cntYPos) * 2;
		}
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 91 - Right triangles with integer coordinates
//	URL:	https://projecteuler.net/problem=91
//	Input:	50
//	Output:	14234
//	Lang:	C++