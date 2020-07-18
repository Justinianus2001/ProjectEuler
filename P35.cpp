#include <iostream>
using namespace std;

inline bool isPrime(int num){
	if(num == 2 || num == 3)					return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline bool isCircularPrime(int num){
	int length = log10(num);
	for(int idx = 1; idx < length; idx ++){
		num = (num % 10) * pow(10, length - 1) + num / 10;
		if(!isPrime(num))		return false;
	}
	return true;
}

int main(){
	int inp, test, length, cnt = 0;
	cin >> inp;
	for(int idx = 2; idx <= inp; idx ++)
		if(isPrime(idx))	cnt += isCircularPrime(idx);
	cout << cnt;
	return 0;
}
//	Title:	Problem 35 - Circular primes
//	URL:	https://projecteuler.net/problem=35
//	Time:	O(nlogn)
//	Input:	1000000
//	Output:	55
//	Lang:	C++
