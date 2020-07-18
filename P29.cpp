#include <cmath>
#include <iostream>
#include <set>
using namespace std;

int main(){
	set<double> ans;
	int inp;	cin >> inp;
	for(double base = 2; base <= inp; base ++)
		for(double exp = 2; exp <= inp; exp ++)
			ans.insert(powl(base, exp));
	cout << ans.size();
	return 0;
}
//	Title:	Problem 29 - Distinct powers
//	URL:	https://projecteuler.net/problem=29
//	Time:	O(n^2)
//	Input:	100
//	Output:	9183
//	Lang:	C++
