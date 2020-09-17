/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

inline vector<string> tokenize(string text, char delim){
	vector<string> tokens;
	int start = text.find_first_not_of(delim), end = 0;
	while((end = text.find_first_of(delim, start)) != string::npos)
		tokens.push_back(text.substr(start, end - start)),
		start = text.find_first_not_of(delim, end);
	if(start != string::npos) tokens.push_back(text.substr(start));
	return tokens;
}

int main(){
	freopen("P082.txt", "r", stdin);
	vector<int> v[500];
	long long dp[500][500], ans = LLONG_MAX;
	int length = 0, width = 0;
	string str;
	while(cin >> str){
		vector<string> token = tokenize(str, ',');
		width = max(width, (int)token.size());
		for(string num: token)	v[length].push_back(stoi(num));
		length ++;
	}
	for(int col = 0; col < width; col ++){
		for(int row = 0; row < length; row ++){
			dp[row][col] = v[row][col];
			if(col)		dp[row][col] += dp[row][col - 1];
		}
		for(int rowDown = 1; rowDown < length; rowDown ++)
			dp[rowDown][col] = min(dp[rowDown][col], dp[rowDown - 1][col] + v[rowDown][col]);
		for(int rowUp = length - 2; rowUp >= 0; rowUp --)
			dp[rowUp][col] = min(dp[rowUp][col], dp[rowUp + 1][col] + v[rowUp][col]);
	}
	for(int row = 0; row < length; row ++)
		ans = min(ans, dp[row][width - 1]);
	cout << ans;
	return 0;
}
//	Title:	Problem 82 - Path sum: three ways
//	URL:	https://projecteuler.net/problem=82
//	Input:	P082.txt
//	Output:	260324
//	Lang:	C++
