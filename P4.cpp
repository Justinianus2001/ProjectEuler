#include <iostream>
using namespace std;

inline bool checkPalindrome(int num){
	int revNum = 0, copy = num;
	while(copy)		revNum = revNum * 10 + copy % 10, copy /= 10;
	return num == revNum;
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
	int inp, ans = 0;
	cin >> inp;
	for(int idx1 = pow(10, inp - 1); idx1 < pow(10, inp); idx1 ++)
		for(int idx2 = pow(10, inp - 1); idx2 < pow(10, inp); idx2 ++)
			if(checkPalindrome(idx1 * idx2))	ans = max(ans, idx1 * idx2);
	cout << ans;
	return 0;
}
//	Title:	Problem 4 - Largest palindrome product
//	URL:	https://projecteuler.net/problem=4
//	Time:	O(sqrt(n))
//	Input:	3
//	Output:	906609
//	Lang:	C++
