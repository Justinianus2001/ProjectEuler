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
	freopen("P081.txt", "r", stdin);
	vector<int> v[500];
	long long dp[500][500];
	int length = 0, width = 0;
	string str;
	while(cin >> str){
		vector<string> token = tokenize(str, ',');
		width = max(width, (int)token.size());
		for(string num: token)	v[length].push_back(stoi(num));
		length ++;
	}
	for(int row = 0; row < length; row ++)
		for(int col = 0; col < width; col ++)
			dp[row][col] = LLONG_MAX;
	dp[0][0] = v[0][0];
	for(int row = 0; row < length; row ++)
		for(int col = 0; col < width; col ++){
			if(row)		dp[row][col] = min(dp[row][col], dp[row - 1][col] + v[row][col]);
			if(col)		dp[row][col] = min(dp[row][col], dp[row][col - 1] + v[row][col]);
		}
	cout << dp[length - 1][width - 1];
	return 0;
}
//	Title:	Problem 81 - Path sum: two ways
//	URL:	https://projecteuler.net/problem=81
//	Input:	P081.txt
//	Output:	427337
//	Lang:	C++
