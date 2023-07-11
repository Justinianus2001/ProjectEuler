/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, cnt = 0;
	cin >> range;
	for(long long len = 1; ; len ++){
		for(long long area = 2; area <= len * 2; area ++){
			long double Sqrt = sqrt(area * area + len * len);
			if(Sqrt == (long long)Sqrt)
				cnt += area <= len ? area / 2 : len - (area + 1) / 2 + 1;
		}
		if(cnt >= range){
			cout << len;
			break;
		}
	}
	return EXIT_SUCCESS;
}
//	Title:	Problem 86 - Cuboid route
//	URL:	https://projecteuler.net/problem=86
//	Input:	1000000
//	Output:	1818
//	Lang:	C++