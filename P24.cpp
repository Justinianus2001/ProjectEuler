#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int inp, cnt = 0;
	string str;
	cin >> str >> inp;
	do if(++ cnt == inp)	break;
	while(next_permutation(begin(str), end(str)));
	cout << str;
	return 0;
}
//	Title:	Problem 24 - Lexicographic permutations
//	URL:	https://projecteuler.net/problem=24
//	Time:	O(n!)
//	Input:	0123456789 1000000
//	Output:	2783915460
//	Lang:	C++
