/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	string str = "0123456789";
	long long range, num, res = 0;
	cin >> range;	sieve(range * 2);
	str = str.substr(0, range + 1);
	do{
		if(str[0] == '0')
			continue;
		bool ok = true;
		for(long long idx = 0; idx < str.length() - 3; idx ++){
			num = stoll(str.substr(idx + 1, 3));
			if(num % primes[idx]){	ok = false;	break;	}
		}
		if(ok)	res += stoll(str);
	}
	while(next_permutation(begin(str), end(str)));
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 43 - Sub-string divisibility
//	URL:	https://projecteuler.net/problem=43
//	Input:	9
//	Output:	16695334890
//	Lang:	C++