/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <climits>
#include <iostream>
#include <queue>
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

priority_queue<pair<long long, pair<int, int>>> pq;
pair<int, int> moves[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
long long val[500][500];
bool visited[500][500];

int main(){
	freopen("P083.txt", "r", stdin);
	vector<int> v[500];
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
			val[row][col] = LLONG_MAX;
	pq.push({val[0][0] = v[0][0], {0, 0}});
	while(pq.size()){
		pair<int, int> cur = pq.top().second;
		pq.pop();
		if(!visited[cur.first][cur.second]){
			visited[cur.first][cur.second] = true;
			for(pair<int, int> move: moves)
				if(cur.first + move.first >= 0 && cur.first + move.first < length
				&& cur.second + move.second >= 0 && cur.second + move.second < width){
					pair<int, int> next = {cur.first + move.first, cur.second + move.second};
					long long nextVal = v[cur.first + move.first][cur.second + move.second];
					if(val[cur.first][cur.second] + nextVal < val[next.first][next.second])
						val[next.first][next.second] = val[cur.first][cur.second] + nextVal,
						pq.push({-val[next.first][next.second], next});
				}
		}
	}
	cout << val[length - 1][width - 1];
	return 0;
}
//	Title:	Problem 83 - Path sum: four ways
//	URL:	https://projecteuler.net/problem=83
//	Input:	P083.txt
//	Output:	425185
//	Lang:	C++
