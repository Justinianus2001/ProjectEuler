/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <cmath>
#include <iostream>
using namespace std;

inline bool isPentagonNum(int num){
	int val = sqrt(num * 24 + 1);
	return val * val == num * 24 + 1 && !((val + 1) % 6);
}

int main(){
	int val1, val2, ans = 0;
	for(int idx1 = 1; ; idx1 ++)
		for(int idx2 = 1; idx2 < idx1; idx2 ++){
			val1 = idx1 * (idx1 * 3 - 1) / 2, val2 = idx2 * (idx2 * 3 - 1) / 2;
			if(isPentagonNum(val1 - val2) && isPentagonNum(val1 + val2)){	ans = val1 - val2;	goto END;	}
		}
	END:;
	cout << ans;
	return 0;
}
//	Title:	Problem 44 - Pentagon numbers
//	URL:	https://projecteuler.net/problem=44
//	Input:
//	Output:	5482660
//	Lang:	C++
