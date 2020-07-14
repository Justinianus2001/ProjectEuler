#include <iostream>
using namespace std;

inline bool isPrime(long long num){
	if(num == 2 || num == 3)					return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(long long idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

int main(){
	long long inp, ans = 0;
	cin >> inp;
	for(long long idx = 1; idx * idx <= inp; idx ++)
		if(!(inp % idx)){
			if(isPrime(inp / idx))	ans = max(ans, inp / idx);
			if(isPrime(idx))		ans = max(ans, idx);
		}
	cout << ans;
	return 0;
}
//	Title:	Problem 3 - Largest prime factor
//	URL:	https://projecteuler.net/problem=3
//	Time:	O(sqrt(num))
//	Input:	600851475143
//	Output:	6857
//	Lang:	C++
