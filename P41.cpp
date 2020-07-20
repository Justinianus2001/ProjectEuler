#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

inline bool isPrime(int num){
	if(num == 2 || num == 3)					return true;
	if(num <= 1 || !(num % 2) || !(num % 3))	return false;
	for(int idx = 5; idx * idx <= num; idx += 6)
		if(!(num % idx) || !(num % (idx + 2)))	return false;
	return true;
}

int main(){
	string form = "123456789", str;
	int inp, ans = 0, num;
	cin >> inp;
	for(int idx = 1; idx <= inp; idx ++){
		str = form.substr(0, idx);
		do{
			num = stoi(str);
			if(isPrime(num))	ans = max(ans, num);
		}
		while(next_permutation(begin(str), end(str)));
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 41 - Pandigital prime
//	URL:	https://projecteuler.net/problem=41
//	Time:	O(n!)
//	Input:	9
//	Output:	7652413
//	Lang:	C++
