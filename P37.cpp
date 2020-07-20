#include <iostream>
using namespace std;

inline bool isPrime(int num){
	if(num == 2 || num == 3)					return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

int main(){
	int inp, check, length, cnt = 0, ans = 0;
	cin >> inp;
	for(int idx1 = 10; cnt < inp; idx1 ++)
		if(isPrime(idx1)){
			check = 1, length = log10(idx1);
			for(int idx2 = 1; idx2 < length; idx2 ++)
				if(!isPrime(idx1 / pow(10, idx2)) || !isPrime(idx1 % pow(10, idx2))){	check = 0;	break;	}
			if(check)	cnt ++, ans += idx1;
		}
	cout << ans;
	return 0;
}
// input:	11
// output:	748317
