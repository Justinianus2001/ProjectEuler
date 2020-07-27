#include <iostream>
using namespace std;

int cntDiv[10000000];

inline void sieve(int num){
	for(int idx1 = 2; idx1 <= num; idx1 += (idx1 != 2) + 1)
		if(!cntDiv[idx1])
			for(int idx2 = idx1; idx2 <= num; idx2 += idx1)
				cntDiv[idx2] ++;
}

int main(){
	sieve(10000000);
	int inp;	cin >> inp;
	for(int idx = 2; idx <= 10000000; idx ++)
		if(cntDiv[idx] == inp){
			bool flag = true;
			for(int base = idx + 1; base < idx + inp; base ++)
				if(cntDiv[base] != inp){	flag = false;	break;		}
			if(flag){	cout << idx;	break;	}
		}
	return 0;
}
//	Title:	Problem 47 - Distinct primes factors
//	URL:	https://projecteuler.net/problem=47
//	Time:	O(10000000)
//	Input:	4
//	Output:	134043
//	Lang:	C++
