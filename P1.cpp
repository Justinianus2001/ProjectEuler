#include <iostream>
using namespace std;

int main(){
	int inp, ans = 0;
	cin >> inp;
	for(int idx = 3; idx < inp; idx ++)
		if(!(idx % 3) || !(idx % 5))	ans += idx;
	cout << ans;
	return 0;
}
//	Title:	Problem 1 - Multiples of 3 and 5
//	URL:	https://projecteuler.net/problem=1
//	Time:	O(n)
//	Input:	1000
//	Output:	233168
//	Lang:	C++
