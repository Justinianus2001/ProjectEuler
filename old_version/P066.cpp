/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	bigInteger maxX = 0;
	long long range, maxD = -1;
	cin >> range;
	for(long long D = 2; D <= range; D ++){
		if(isSquareVal(D))	continue;
		long long sqrtD = sqrt(D), a = sqrtD,
			numerator = 0, denominator = 1;
		bigInteger x[] = {0, 1, bigInteger(a)},
				y[] = {0, 0, 1};
		while(true){
			numerator = denominator * a - numerator,
			denominator = (D - numerator * numerator) / denominator,
			a = (sqrtD + numerator) / denominator,
			x[0] = x[1], x[1] = x[2], x[2] = (x[1] * a) + x[0],
			y[0] = y[1], y[1] = y[2], y[2] = (y[1] * a) + y[0];
			bigInteger lhs = x[2] * x[2],
					rhs = (y[2] * (y[2] * D)) + 1;
			if(lhs == rhs)		break;
		}
		if(x[2] > maxX)
			maxX = x[2], maxD = D;
	}
	cout << maxD;
	return EXIT_SUCCESS;
}
//	Title:	Problem 66 - Diophantine equation
//	URL:	https://projecteuler.net/problem=66
//	Input:	1000
//	Output:	661
//	Lang:	C++