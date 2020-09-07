#include <cmath>
#include <iostream>
using namespace std;

int main(){
	int inp, cnt = 0;	cin >> inp;
	for(int num = 2; num <= inp; num ++){
		int root = sqrt(num),
			numerator = 0, denominator = 1,
			a = root, cntPeriod = 0;
		if(root * root == num)	continue;
		while(a != root * 2)
			numerator = denominator * a - numerator,
			denominator = (num - numerator * numerator) / denominator,
			a = (root + numerator) / denominator,
			cntPeriod ++;
		cnt += cntPeriod % 2;
	}
	cout << cnt;
	return 0;
}
//	Title:	Problem 64 - Odd period square roots
//	URL:	https://projecteuler.net/problem=64
//	Time:	O(?)
//	Input:	10000
//	Output:	1322
//	Lang:	C++
