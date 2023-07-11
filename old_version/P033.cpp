/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	fraction mul(1, 1);
	long long digits;	cin >> digits;
	for(long long numerator = pow(10, digits - 1); numerator < pow(10, digits); numerator ++){
		vector<long long> num = getVector(numerator);
		for(long long denominator = numerator + 1; denominator < pow(10, digits); denominator ++){
			vector<long long> den = getVector(denominator);
			bool ok = false;
			for(long long digit = 1; digit < 10; digit ++){
				vector<long long> num1 = num, num2 = den;
				num1.erase(remove(begin(num1), end(num1), digit), end(num1)),
				num2.erase(remove(begin(num2), end(num2), digit), end(num2));
				fraction l(numerator, denominator), r(getNum(num1), getNum(num2));
				if(getNum(num1) != numerator && getNum(num2) != denominator && l == r)
					ok = true;
			}
			if(ok){
				fraction frac(numerator, denominator);
				mul *= frac;
			}
		}
	}
	cout << mul.getDenominator();
	return EXIT_SUCCESS;
}
//	Title:	Problem 33 - Digit cancelling fractions
//	URL:	https://projecteuler.net/problem=33
//	Input:	2
//	Output:	100
//	Lang:	C++
