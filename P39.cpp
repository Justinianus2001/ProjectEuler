#include <iostream>
#include <map>
using namespace std;

inline int __gcd(int lhs, int rhs){
	if(!rhs)	return lhs;
	return __gcd(rhs, lhs % rhs);
}

int main(){
	map<int, int> mp;
	int inp, side1, side2, side3, sum, base, max = 0, ans = 0;
	cin >> inp;
	for(int idx1 = 2; idx1 * idx1 <= inp; idx1 ++)
		for(int idx2 = 1; idx2 < idx1; idx2 ++){
			if(!((idx1 + idx2) % 2) || __gcd(idx1, idx2) != 1)		continue;
			side1 = idx1 * idx1 - idx2 * idx2, side2 = idx1 * idx2 * 2, side3 = idx1 * idx1 + idx2 * idx2,
			sum = side1 + side2 + side3, base = 1;
			while(base * sum <= inp)	mp[base * sum] ++, base ++;
		}
	for(int idx = 12; idx <= inp; idx ++)
		if(mp[idx] > max)		max = mp[idx], ans = idx;
	cout << ans;
	return 0;
}
//	Title:	Problem 39 - Integer right triangles
//	URL:	https://projecteuler.net/problem=39
//	Time:	O(n)
//	Input:	1000
//	Output:	840
//	Lang:	C++
