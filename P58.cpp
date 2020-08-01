#include <iostream>
using namespace std;

inline bool isPrime(int num){
	if(num == 2 || num == 3)			return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

int main(){
	double n, cntPrime = 0, cntAll = 1;
	int num = 1, ans = 3;
	cin >> n;	n /= 100;
	while(true){
		for(int idx = 0; idx < 4; idx ++){
			num += ans - 1, cntAll ++;
			if(isPrime(num))	cntPrime ++;
		}
		if(cntPrime / cntAll < n)	break;
		else				ans += 2;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 58 - Spiral primes
//	URL:	https://projecteuler.net/problem=58
//	Time:	O(?)
//	Input:	10
//	Output:	26241
//	Lang:	C++
