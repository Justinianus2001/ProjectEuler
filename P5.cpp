#include <iostream>
using namespace std;

inline long long __gcd(long long lhs, long long rhs){
	if(!rhs)	return lhs;
	return __gcd(rhs, lhs % rhs);
}

int main(){
	long long ans = 1;
	int inp;		cin >> inp;
	for(long long idx = 2; idx <= inp; idx ++)
		ans *= idx / __gcd(ans, idx);
	cout << ans;
	return 0;
}
//	Title:	Problem 5 - Smallest multiple
//	URL:	https://projecteuler.net/problem=5
//	Time:	O(n)
//	Input:	20
//	Output:	232792560
//	Lang:	C++
