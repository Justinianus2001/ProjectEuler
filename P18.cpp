#include <iostream>
using namespace std;

int arr[100][100];

inline int sum(int idx1, int idx2){
	if(!idx1)		return arr[0][0];
	if(!idx2)		return arr[idx1][idx2] + sum(idx1 - 1, idx2);
	if(idx1 == idx2)	return arr[idx1][idx2] + sum(idx1 - 1, idx2 - 1);
	return arr[idx1][idx2] + max(sum(idx1 - 1, idx2), sum(idx1 - 1, idx2 - 1));
}

int main(){
	int inp, ans = 0;
	cin >> inp;
	for(int idx1 = 0; idx1 < inp; idx1 ++)
		for(int idx2 = 0; idx2 <= idx1; idx2 ++)	cin >> arr[idx1][idx2];
	for(int idx = 0; idx < inp; idx ++)
		ans = max(ans, sum(inp, idx));
	cout << ans;
	return 0;
}
//	Title:	Problem 18 - Maximum path sum I
//	URL:	https://projecteuler.net/problem=18
//	Time:	O(n)
//	Input:	15
//		75
//		95 64
//		17 47 82
//		18 35 87 10
//		20 04 82 47 65
//		19 01 23 75 03 34
//		88 02 77 73 07 63 67
//		99 65 04 28 06 16 70 92
//		41 41 26 56 83 40 80 70 33
//		41 48 72 33 47 32 37 16 94 29
//		53 71 44 65 25 43 91 52 97 51 14
//		70 11 33 28 77 73 17 78 39 68 17 57
//		91 71 52 38 17 14 91 43 58 50 27 29 48
//		63 66 04 68 89 53 67 30 73 16 69 87 40 31
//		04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
//	Output:	1074
//	Lang:	C++
