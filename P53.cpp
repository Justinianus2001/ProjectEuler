#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> row;
	int inp, lb, ans = 0;
	cin >> inp >> lb;
	for(int step = 0; step <= inp; step ++){
		for(int idx = row.size() - 1; idx >= 0; idx --){
			row[idx] += row[idx - 1];
			if(row[idx] > lb)	row[idx] = lb + 1, ans ++;
		}
		row.push_back(1);
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 53 - Combinatoric selections
//	URL:	https://projecteuler.net/problem=53
//	Time:	O(n*(n+1)/2)
//	Input:	100 1000000
//	Output:	4075
//	Lang:	C++
