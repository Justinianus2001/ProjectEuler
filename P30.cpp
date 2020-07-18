#include <iostream>
using namespace std;

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline int sumPowDigit(int num, int base){
	int sum = 0;
	while(num)	sum += pow(num % 10, base), num /= 10;
	return sum;
}

int main(){
	int inp, inf = 1, ans = 0;
	cin >> inp;
	while(inf * pow(9, inp) >= pow(10, inf - 1))	inf ++;
	for(int idx = 2; idx <= inf * pow(9, inp); idx ++)
		if(sumPowDigit(idx, inp) == idx)
			ans += idx;
	cout << ans;
	return 0;
}
//	Title:	Problem 30 - Digit fifth powers
//	URL:	https://projecteuler.net/problem=30
//	Time:	O(n*(9^n))
//	Input:	5
//	Output:	443839
//	Lang:	C++
