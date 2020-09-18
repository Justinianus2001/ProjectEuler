/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
	srand(0);
	set<pair<double, int>, greater<pair<double, int>>> rank;
	int diceSide, modalStr,
		maxTurn = 1000000,
		numCell = 40, cntPop[40] = {},
		CC[] = {2, 17, 33},
		CH[] = {7, 22, 36},
		R[] = {5, 15, 25},
		U[] = {12, 12, 28},
		cur = 0, cntDbl = 0;
	vector<int> chest, chance;
	cin >> diceSide >> modalStr;
	int need = modalStr / 2;
	for(int card = 1; card <= 16; card ++)
		chest.push_back(card),
		chance.push_back(card);
	random_shuffle(begin(chest), end(chest)),
	random_shuffle(begin(chance), end(chance));
	for(int turn = 1; turn <= maxTurn; turn ++){
		int dice1 = (rand() % diceSide) + 1,
			dice2 = (rand() % diceSide) + 1,
			next = (cur + dice1 + dice2) % numCell;
		if(dice1 == dice2)	cntDbl ++;
		else		cntDbl = 0;
		if(cntDbl == 3)		next = 10, cntDbl = 0;
		for(int type = 0; type < 3; type ++)
			if(next == CC[type]){
				switch(chest.front()){
					case 1:		next = 0;		break;
					case 2:		next = 10;		break;
				}
				rotate(begin(chest), begin(chest) + 1, end(chest));
			}
			else if(next == CH[type]){
				switch(chance.front()){
					case 1:		next = 0;		break;
					case 2:		next = 10;		break;
					case 3:		next = 11;		break;
					case 4:		next = 24;		break;
					case 5:		next = 39;		break;
					case 6:		next = R[0];	break;
					case 7:
					case 8:		next = R[(type + 1) % 3];
							break;
					case 9:		next = U[(type + 1) % 3];
					case 10:	next -= 3;		break;
				}
				rotate(begin(chance), begin(chance) + 1, end(chance));
			}
		if(next == 30)		next = 10;
		cntPop[next] ++, cur = next;
	}
	for(int cell = 0; cell < 40; cell ++)
		rank.insert({cntPop[cell] * 100.0 / maxTurn, cell});
	while(need --){
		int top = begin(rank)->second;
		rank.erase(begin(rank));
		if(top < 10)	cout << '0';
		cout << top;
	}
	return 0;
}
//	Title:	Problem 84 - Monopoly odds
//	URL:	https://projecteuler.net/problem=84
//	Input:	4 6
//	Output:	101524
//	Lang:	C++
