/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P096.txt", "r", stdin);
	long long res = 0;
	string intro;
	while(cin >> intro >> intro){
		bool square[3][3][10] = {}, row[9][10] = {}, col[9][10] = {};
		string str;
		for(long long rowIdx = 0; rowIdx < 9; rowIdx ++){
			cin >> str;
			for(long long colIdx = 0; colIdx < 9; colIdx ++){
				long long num = stoi(str[colIdx]);
				sudoku[rowIdx][colIdx] = num,
				square[rowIdx / 3][colIdx / 3][num] = row[rowIdx][num] = col[colIdx][num] = true;
			}
		}
		solveSudoku(0, 0, square, row, col);
		res += concat(resSudoku[0][0], concat(resSudoku[0][1], resSudoku[0][2]));
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 96 - Su Doku
//	URL:	https://projecteuler.net/problem=96
//	Input:	PT096.txt
//	Output:	24702
//	Lang:	C++