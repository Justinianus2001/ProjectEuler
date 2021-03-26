/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	sieve(100000);
	vector<long long> abundant;
	long long range, sum = 0;	cin >> range;
	bool *isSumOf2Abundant = new bool[min(range + 1, 28124)]();
	for(long long num = 1; num <= min(range, 28123); num ++){
		if(!isSumOf2Abundant[num])
			sum += num;
		if(sumDiv(num, primes) > num){
			abundant.push_back(num);
			for(long long prev: abundant){
				if(num + prev > min(range, 28123))	break;
				isSumOf2Abundant[num + prev] = true;
			}
		}
	}
	cout << sum;
	return EXIT_SUCCESS;
}
//	Title:	Problem 23 - Non-abundant sums
//	URL:	https://projecteuler.net/problem=23
//	Input:	28123
//	Output:	4179871
//	Lang:	C++
