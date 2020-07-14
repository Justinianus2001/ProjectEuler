#include <iostream>
using namespace std;

inline bool isPrime(int num){
	if(num == 2 || num == 3)					return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

int main(){
	long long ans = 0;
	int inp;		cin >> inp;
	for(int idx = 2; idx < inp; idx += (idx != 2) + 1)
		if(isPrime(idx))	ans += idx;
	cout << ans;
	return 0;
}
//	Title:	Problem 10 - Summation of primes
//	URL:	https://projecteuler.net/problem=10
//	Time:	O(nlogn)
//	Input:	2000000
//	Output:	142913828922
//	Lang:	C++
