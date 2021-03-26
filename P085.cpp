/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long need, nearest = INT_MAX,
		res, height, width = 1;
	cin >> need;		height = need;
	while(height >= width){
		long long numRect = getTriangularVal(height) * getTriangularVal(width);
		if(abs(numRect - need) < nearest)
			nearest = abs(numRect - need),
			res = height * width;
		if(numRect > need)	height --;
		else			width ++;
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 85 - Counting rectangles
//	URL:	https://projecteuler.net/problem=85
//	Input:	2000000
//	Output:	2772
//	Lang:	C++