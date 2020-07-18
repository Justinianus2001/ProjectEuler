#include <iostream>
#include <map>
using namespace std;

inline bool isPandigital(int mulplicand, int mulplier, int product, int num){
	int mp[num + 1] = {};
	while(mulplicand)
		if(mulplicand % 10 > num || mp[mulplicand % 10] ++)	return false;
		else	mulplicand /= 10;
	while(mulplier)
		if(mulplier % 10 > num || mp[mulplier % 10] ++)		return false;
		else	mulplier /= 10;
	while(product)
		if(product % 10 > num || mp[product % 10] ++)		return false;
		else	product /= 10;
	if(mp[0])		return false;
	for(int i = 1; i <= num; i ++)
		if(!mp[i])	return false;
	return true;
}

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

int main(){
	map<int, bool> mp;
	int inp, ans = 0;
	cin >> inp;
	for(int idx1 = 1; log10(idx1) < inp / 2; idx1 ++)
		for(int idx2 = idx1 + 1; log10(idx1) + log10(idx2) + log10(idx1 * idx2) <= inp; idx2 ++)
			if(isPandigital(idx1, idx2, idx1 * idx2, inp) && !mp[idx1 * idx2])
				ans += idx1 * idx2, mp[idx1 * idx2] = true;
	cout << ans;
	return 0;
}
//	Title:	Problem 32 - Pandigital products
//	URL:	https://projecteuler.net/problem=32
//	Time:	O(10^(n/2))
//	Input:	9
//	Output:	45228
//	Lang:	C++
