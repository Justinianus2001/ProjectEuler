/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	vector<long long> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	set<long long> s;
	long long length;	cin >> length;
	v.resize(length);
	do
		for(long long lenA = 1; lenA < length; lenA ++)
			for(long long lenB = 1; lenB < length - lenA; lenB ++){
				long long lenC = length - lenA - lenB,
					A = 0, B = 0, C = 0, idx = 0;
				if(lenA > lenC || lenB > lenC)
					break;
				for(long long pos = 0; pos < lenA; pos ++)
					A = A * 10 + v[idx ++];
				for(long long pos = 0; pos < lenB; pos ++)
					B = B * 10 + v[idx ++];
				for(long long pos = 0; pos < lenC; pos ++)
					C = C * 10 + v[idx ++];
				if(A * B == C)
					s.insert(A * B);
			}
	while(next_permutation(begin(v), end(v)));
	cout << accumulate(begin(s), end(s), 0LL);
	return EXIT_SUCCESS;
}
//	Title:	Problem 32 - Pandigital products
//	URL:	https://projecteuler.net/problem=32
//	Input:	9
//	Output:	45228
//	Lang:	C++
