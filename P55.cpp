#include <iostream>
using namespace std;

inline bool isPalindrome(string str){
	int length = str.length();
	for(int idx = 0; idx < length / 2; idx ++)
		if(str[idx] != str[length - idx - 1])		return false;
	return true;
}

inline string addString(string lhs, string rhs){
	int add = 0;
	for(int i = lhs.length() - 1; i >= 0; i --){
		lhs[i] = (char)(lhs[i] + rhs[i] - '0') + add, add = 0;
		if(lhs[i] > '9')	lhs[i] -= 10, add = 1;
	}
	if(add)		return '1' + lhs;
	return lhs;
}

inline string reverse(string str){
	string ans;
	for(char ch: str)	ans = ch + ans;
	return ans;
}

int main(){
	string revNum, numStr;
	int inp, ans = 0;	cin >> inp;
	for(int num = 1; num < inp; num ++){
		numStr = to_string(num);
		for(int turn = 1; turn <= 50; turn ++){
			revNum = reverse(numStr), numStr = addString(numStr, revNum);
			if(isPalindrome(numStr))	goto NEXT;
		}
		ans ++;
		NEXT:;
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 55 - Lychrel numbers
//	URL:	https://projecteuler.net/problem=55
//	Time:	O(n*50)
//	Input:	10000
//	Output:	249
//	Lang:	C++
