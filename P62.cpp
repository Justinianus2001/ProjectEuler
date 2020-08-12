#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string, pair<int, long long>> mp;
	int inp;	cin >> inp;
	for(long long idx = 1; ; idx ++){
		string strNum = to_string(idx * idx * idx);
		sort(begin(strNum), end(strNum));
		if(!mp[strNum].second)	mp[strNum].second = idx * idx * idx;
		if(++ mp[strNum].first == inp){
			cout << mp[strNum].second;
			break;
		}
	}
	return 0;
}
//	Title:	Problem 62 - Cubic permutations
//	URL:	https://projecteuler.net/problem=62
//	Time:	O(?)
//	Input:	5
//	Output:	127035954683
//	Lang:	C++
