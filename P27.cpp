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
	int inp, maxCnt = 0, cnt, ans = 0;
	cin >> inp;
	for(int idx1 = 2; idx1 < inp; idx1 += (idx1 != 2) + 1)
		if(isPrime(idx1))
			for(int idx2 = - inp + 1; idx2 < inp; idx2 ++){
				cnt = 0;
				for(int idx3 = 0; isPrime(idx3 * idx3 + idx3 * idx2 + idx1); idx3 ++, cnt ++);
				if(cnt > maxCnt)	maxCnt = cnt, ans = idx1 * idx2;
			}
	cout << ans;
	return 0;
}
//	Title:	Problem 27 - Quadratic primes
//	URL:	https://projecteuler.net/problem=27
//	Time:	O(n*sqrt(n))
//	Input:	1000
//	Output:	-59231
//	Lang:	C++
