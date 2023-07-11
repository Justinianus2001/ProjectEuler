#include <bits/stdc++.h>
using namespace std;

int PE028(int num) {
	num >>= 1;
	int res, s1 = num - 1, s2 = num, s3 = num + 1;
	!(s1 % 3) ? s1 /= 3 : !(s2 % 3) ? s2 /= 3 : s3 /= 3;
	res = s1 * s2 * s3 + num * num * num * 5 + num * num * 10 + num * 9 + 1;
	return res;
}