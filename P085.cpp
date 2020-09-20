/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <climits>
#include <iostream>
using namespace std;

int main(){
	long long inp, nearest = INT_MAX, 
		ans, height, width = 1;
	cin >> inp;		height = inp;
	while(height >= width){
		long long numRect = height * (height + 1) * width * (width + 1) / 4;
		if(abs(numRect - inp) < nearest)
			nearest = abs(numRect - inp),
			ans = height * width;
		if(numRect > inp)	height --;
		else		width ++;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 85 - Counting rectangles
//	URL:	https://projecteuler.net/problem=85
//	Input:	2000000
//	Output:	2772
//	Lang:	C++
