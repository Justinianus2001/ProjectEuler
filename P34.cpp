#include <iostream>
using namespace std;

int main(){
	int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880},
		inp, sumFact, num, ans = 0;
	cin >> inp;		inp *= fact[9];
	for(int idx = 10; idx <= inp; idx ++){
		sumFact = 0, num = idx;
		while(num)	sumFact += fact[num % 10], num /= 10;
		if(sumFact == idx)	ans += sumFact;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 34 - Digit factorials
//	URL:	https://projecteuler.net/problem=34
//	Time:	O(n)
//	Input:	8 (8 * 9!)
//	Output:	40730
//	Lang:	C++
