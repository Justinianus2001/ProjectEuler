#include <iostream>
using namespace std;

int main(){
	int inp, ans = 1;
	cin >> inp;		inp /= 2;
	for(int idx = inp - 1; idx <= inp + 1; idx ++)
		ans *= !(idx % 3) ? idx / 3 : idx;
	ans += inp * inp * inp * 5 + inp * inp * 10 + inp * 9 + 1;
	cout << ans;
	return 0;
}
//	Title:	Problem 28 - Number spiral diagonals
//	URL:	https://projecteuler.net/problem=28
//	Time:	O(3)
//	Input:	1001
//	Output:	669171001
//	Lang:	C++
