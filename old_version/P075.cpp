/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long range, res = 0;	cin >> range;
	vector<int> v(range + 1);
	for(long long m = 2; m * m <= range; m ++)
		for(long long n = 1; n < m; n ++){
			if(!((m + n) % 2) || __gcd(m, n) != 1)		continue;
			long long A = m * m - n * n,
				B = 2 * m * n,
				C = m * m + n * n,
				sumABC = A + B + C;
			for(int mul = 1; sumABC * mul <= range; mul ++)
				v[sumABC * mul] ++;
		}
	for(long long idx = 12; idx <= range; idx ++)
		res += (v[idx] == 1);
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 75 - Singular integer right triangles
//	URL:	https://projecteuler.net/problem=75
//	Input:	1500000
//	Output:	161667
//	Lang:	C++