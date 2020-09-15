/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

int main(){
	int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880},
		inp, chain, ans = 0;
	cin >> inp >> chain;
	for(int num = 1; num < inp; num ++){
		int cnt = 1, temp = num;
		while(true){
			if(temp == 1 || temp == 2
			|| temp == 145 || cnt > chain)		break;
			if(temp == 169 || temp == 363601
			|| temp == 1454){	cnt += 2;	break;	}
			if(temp == 871 || temp == 45361
			|| temp == 872 || temp == 45362){	cnt ++;		break;	}
			int next = 0;
			while(temp)		next += fact[temp % 10], temp /= 10;
			temp = next, cnt ++;
		}
		ans += (cnt == chain);
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 74 - Digit factorial chains
//	URL:	https://projecteuler.net/problem=74
//	Input:	1000000 60
//	Output:	402
//	Lang:	C++
