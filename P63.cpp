#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int inp, cnt = 0;	cin >> inp;
	for(int exp = 1; ; exp ++){
		bool haveNew = false;
		for(int base = 1; base <= inp; base ++)
			if((int)log10(powl(base, exp)) + 1 == exp)	cnt ++, haveNew = true;
		if(!haveNew)	break;
	}
	cout << cnt;
	return 0;
}
//	Title:	Problem 63 - Powerful digit counts
//	URL:	https://projecteuler.net/problem=63
//	Time:	O(?)
//	Input:	9
//	Output:	49
//	Lang:	C++
