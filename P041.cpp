/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	string perm = "123456789", str;
	int range, res = 0, num;
	cin >> range;
	for(int len = 1; len <= range; len ++){
		str = perm.substr(0, len);
		do{
			num = stoll(str);
			if(isPrime(num))	res = max(res, num);
		}
		while(next_permutation(begin(str), end(str)));
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 41 - Pandigital prime
//	URL:	https://projecteuler.net/problem=41
//	Input:	9
//	Output:	7652413
//	Lang:	C++