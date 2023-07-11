#include <bits/stdc++.h>
using namespace std;

int PE083() {
	freopen("PE083.txt", "r", stdin);
	vector<vector<int>> grid;
	string str;
	while (getline(cin, str)) {
		stringstream ss(str);
		vector<int> row;
		while (getline(ss, str, ',')) {
			row.push_back(stoi(str));
		}
		grid.push_back(row);
	}
	function<int(vector<vector<int>>)> dijkstra2DArrayVer3 = [] (vector<vector<int>> grid) {
		struct cell {
			int row, col, val;
			cell() {}
			cell(int r, int c, int v) : row(r), col(c), val(v) {}
		};
		struct compareCell {
			bool operator()(const cell& a, const cell& b) const {
		        return a.val > b.val;
		    }
		};
		int n = grid.size(), m = grid[0].size();
		vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		vector<vector<int>> dist(n, vector<int>(m, -1));
		priority_queue<cell, vector<cell>, compareCell> pq;
		dist[0][0] = grid[0][0];
		pq.push(cell(0, 0, dist[0][0]));
		while (pq.size()) {
			cell cur = pq.top();
			pq.pop();
			for (pair<int, int> move: moves) {
				int nextRow = cur.row + move.first, nextCol = cur.col + move.second;
				if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && (dist[nextRow][nextCol] == -1 || cur.val + grid[nextRow][nextCol] < dist[nextRow][nextCol])) {
					dist[nextRow][nextCol] = cur.val + grid[nextRow][nextCol];
					pq.push(cell(nextRow, nextCol, dist[nextRow][nextCol]));
				}
			}
		}
		return dist[n - 1][m - 1];
	};
	cin.clear();
	return dijkstra2DArrayVer3(grid);
}