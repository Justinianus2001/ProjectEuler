/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

int main(){
	int inp, ans = 0;
	cin >> inp;
	for(int idx1 = 3; idx1 < inp; idx1 ++)
		for(int idx2 = idx1 + 1; idx2 < inp - idx1; idx2 ++){
			int idx3 = inp - idx1 - idx2;
			if(idx1 * idx1 + idx2 * idx2 == idx3 * idx3){
				ans = idx1 * idx2 * idx3;	goto END;
			}
		}
	END:;
	cout << ans;
	return 0;
}
//	Title:	Problem 9 - Special Pythagorean triplet
//	URL:	https://projecteuler.net/problem=9
//	Input:	1000
//	Output:	31875000
//	Lang:	C++
