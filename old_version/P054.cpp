/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P054.txt", "r", stdin);
	long long res = 0;
	while(!(cin.eof())){
		vector<pair<long long, long long>> player[2]; 
		string card;
		for(long long idx = 0; idx < 10; idx ++){
			cin >> card;
			player[idx / 5].push_back(card2Pair(card));
		}
		vector<bool> rank[2];
		for(long long playerIdx = 0; playerIdx < 2; playerIdx ++){
			rank[playerIdx].push_back(isRoyalFlush(player[playerIdx]));
			rank[playerIdx].push_back(isStraightFlush(player[playerIdx]));
			rank[playerIdx].push_back(isFourOfAKind(player[playerIdx]));
			rank[playerIdx].push_back(isFullHouse(player[playerIdx]));
			rank[playerIdx].push_back(isFlush(player[playerIdx]));
			rank[playerIdx].push_back(isStraight(player[playerIdx]));
			rank[playerIdx].push_back(isThreeOfAKind(player[playerIdx]));
			rank[playerIdx].push_back(isTwoPairs(player[playerIdx]));
			rank[playerIdx].push_back(isOnePair(player[playerIdx]));
			rank[playerIdx].push_back(isHighCard(player[playerIdx]));
		}
		for(long long rankIdx = 0; rankIdx < 10; rankIdx ++){
			if(rank[0][rankIdx] || rank[1][rankIdx]){
				if(rank[0][rankIdx] && rank[1][rankIdx]){
					switch(rankIdx){
						case 0:		res += cmpRoyalFlush(player[0], player[1]);		break;
						case 1:		res += cmpStraightFlush(player[0], player[1]);	break;
						case 2:		res += cmpFourOfAKind(player[0], player[1]);	break;
						case 3:		res += cmpFullHouse(player[0], player[1]);		break;
						case 4:		res += cmpFlush(player[0], player[1]);			break;
						case 5:		res += cmpStraight(player[0], player[1]);		break;
						case 6:		res += cmpThreeOfAKind(player[0], player[1]);	break;
						case 7:		res += cmpTwoPairs(player[0], player[1]);		break;
						case 8:		res += cmpOnePair(player[0], player[1]);		break;
						case 9:		res += cmpHighCard(player[0], player[1]);		break;
					}
				}
				else	res += rank[0][rankIdx];
				break;
			}
		}
	}
	cout << res;
	return EXIT_SUCCESS;
}
//	Title:	Problem 54 - Poker hands
//	URL:	https://projecteuler.net/problem=54
//	Input:	P054.txt
//	Output:	376
//	Lang:	C++