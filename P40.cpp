#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> list;
	string champernowne = "";
	int inp, num, ans = 1;
	cin >> inp;
	while(inp --)	cin >> num, list.push_back(num);
	sort(begin(list), end(list));
	for(int idx = 0; champernowne.length() <= list.back(); idx ++)
		champernowne += to_string(idx);
	for(int val: list)
		ans *= champernowne[val] - '0';
	cout << ans;
	return 0;
}
//	Title:	Problem 40 - Champernowne's constant
//	URL:	https://projecteuler.net/problem=40
//	Time:	O(?)
//	Input:	7
//		1 10 100 1000 10000 100000 1000000
//	Output:	210
//	Lang:	C++
