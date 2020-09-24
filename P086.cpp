/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <cmath>
#include <iostream>
using namespace std;

int main(){
	int inp, cnt = 0, len;
	cin >> inp;
	for(len = 1; ; len ++){
		for(int widHei = 2; widHei <= len * 2; widHei ++){
			double Sqrt = sqrt(widHei * widHei + len * len);
			if(Sqrt == (int)Sqrt)
				cnt += widHei <= len ? widHei / 2 : len - (widHei + 1) / 2 + 1;
		}
		if(cnt >= inp)	break;
	}
	cout << len;
	return 0;
}
//	Title:	Problem 86 - Cuboid route
//	URL:	https://projecteuler.net/problem=86
//	Input:	1000000
//	Output:	1818
//	Lang:	C++
