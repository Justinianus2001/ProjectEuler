/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline int __gcd(int lhs, int rhs){
	if(!rhs)	return lhs;
	return __gcd(rhs, lhs % rhs);
}

int main(){
	int inp, baseX, baseY, xGcd, yGcd;
	cin >> inp;
	int ans = inp * inp * 3;
	for(int xy = 1; xy <= inp; xy ++)
		ans += min(inp - xy, xy) * 2;
	for(int x = 2; x <= inp; x ++)
		for(int y = 1; y < x; y ++){
			xGcd = x / __gcd(x, y),
			yGcd = y / __gcd(x, y),
			baseX = xGcd, baseY = yGcd;
			while(baseX + y <= inp && x - baseY > -1)
				ans += 2, baseX += xGcd, baseY += yGcd;
			baseX = xGcd, baseY = yGcd;
			while(y - baseX > -1 && x + baseY <= inp)
				ans += 2, baseX += xGcd, baseY += yGcd;
		}
	cout << ans;
	return 0;
}
//	Title:	Problem 91 - Right triangles with integer coordinates
//	URL:	https://projecteuler.net/problem=91
//	Input:	50
//	Output:	14234
//	Lang:	C++
