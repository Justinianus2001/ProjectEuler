/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

priority_queue<pair<long long, pair<long long, long long>>> pq;
pair<long long, long long> moves[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
long long cache[500][500];
bool visited[500][500];

int main(int argc, char** argv){
	freopen("P083.txt", "r", stdin);
	vector<long long> v[500];
	long long len = 0, width = 0;
	string str;
	while(cin >> str){
		vector<string> token = tokenize(str, ",");
		width = max(width, (long long)token.size());
		for(string num: token)	v[len].push_back(stoi(num));
		len ++;
	}
	for(long long row = 0; row < len; row ++)
		for(long long col = 0; col < width; col ++)
			cache[row][col] = LLONG_MAX;
	pq.push({cache[0][0] = v[0][0], {0, 0}});
	while(pq.size()){
		pair<long long, long long> cur = pq.top().second;
		pq.pop();
		if(!visited[cur.first][cur.second]){
			visited[cur.first][cur.second] = true;
			for(pair<long long, long long> move: moves)
				if(cur.first + move.first >= 0 && cur.first + move.first < len
				&& cur.second + move.second >= 0 && cur.second + move.second < width){
					pair<long long, long long> next = {cur.first + move.first, cur.second + move.second};
					long long nextVal = v[cur.first + move.first][cur.second + move.second];
					if(cache[cur.first][cur.second] + nextVal < cache[next.first][next.second])
						cache[next.first][next.second] = cache[cur.first][cur.second] + nextVal,
						pq.push({-cache[next.first][next.second], next});
				}
		}
	}
	cout << cache[len - 1][width - 1];
	return EXIT_SUCCESS;
}
//	Title:	Problem 83 - Path sum: four ways
//	URL:	https://projecteuler.net/problem=83
//	Input:	P083.txt
//	Output:	425185
//	Lang:	C++