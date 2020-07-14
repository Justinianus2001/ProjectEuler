#include <iostream>
using namespace std;

int main(){
	int inp, ans = 0, val1 = 1, val2 = 2, next;
	cin >> inp;
	while(val2 <= inp){
		if(!(val2 % 2))		ans += val2;
		next = val1 + val2, val1 = val2, val2 = next;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 2 - Even Fibonacci numbers
//	URL:	https://projecteuler.net/problem=2
//	Time:	O(n)
//	Input:	4000000
//	Output:	4613732
//	Lang:	C++
