/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

int main(){
	string val1 = "0", val2 = "1", val3;
	int inp, add, cnt = 1;
	cin >> inp;
	while(inp != val2.length()){
		val3 = val1, val1 = val2, add = 0;
		if(val3.length() != val2.length())	val3 = '0' + val3;
		for(int idx = val3.length() - 1; idx > -1; idx --){
			val2[idx] += val3[idx] - '0' + add, add = 0;
			if(val2[idx] > '9')	val2[idx] -= 10, add = 1;
		}
		if(add)		val2 = '1' + val2;
		cnt ++;
	}
	cout << cnt;
	return 0;
}
//	Title:	Problem 25 - 1000-digit Fibonacci number
//	URL:	https://projecteuler.net/problem=25
//	Input:	1000
//	Output:	4782
//	Lang:	C++
