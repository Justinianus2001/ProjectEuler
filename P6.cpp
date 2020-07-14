#include <iostream>
using namespace std;

int main(){
	long long sqrtSum, sum = 0, sumSqrt = 0;
	int inp;	cin >> inp;
	for(int idx = 1; idx <= inp; idx ++)	sum += idx, sumSqrt += idx * idx;
	sqrtSum = sum * sum;
	cout << sqrtSum - sumSqrt;
	return 0;
}
//	Title:	Problem 6 - Sum square difference
//	URL:	https://projecteuler.net/problem=6
//	Time:	O(n)
//	Input:	100
//	Output:	25164150
//	Lang:	C++
