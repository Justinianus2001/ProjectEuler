#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

inline pair<int, int> convert(string card){
	pair<int, int> ans;
	switch(card[0]){
		case 'A':	ans.first = 14;		break;
		case 'K':	ans.first = 13;		break;
		case 'Q':	ans.first = 12;		break;
		case 'J':	ans.first = 11;		break;
		case 'T':	ans.first = 10;		break;
		default:	ans.first = card[0] - '0';
	}
	switch(card[1]){
		case 'S':	ans.second = 0;		break;
		case 'C':	ans.second = 1;		break;
		case 'D':	ans.second = 2;		break;
		case 'H':	ans.second = 3;
	}
	return ans;
}

inline bool cmpHighCard(pair<int, int> lhs, pair<int, int> rhs){
	return lhs.first > rhs.first;
}

int main(){
	freopen("P54.txt", "r", stdin);
	int ans = 0;
	while(!cin.eof()){
		pair<int, int> player[2][5];
		string card;
		int val[2];
		for(int idx = 0; idx < 10; idx ++){
			cin >> card;
			player[idx / 5][idx % 5] = convert(card);
		}
		for(int turn = 0; turn < 2; turn ++){
			int cnt[15] = {}, suit[4] = {}, cntPair = 0;
			bool mp[15][4] = {},
				isThreeOfAKind = false, isStraight = false,
				isFlush = false, isFourOfAKind = false;
			for(pair<int, int> cardVal: player[turn])
				mp[cardVal.first][cardVal.second] = true;
			for(int idx1 = 2; idx1 < 15; idx1 ++){
				for(int idx2 = 0; idx2 < 4; idx2 ++)
					if(mp[idx1][idx2])	suit[idx2] ++, cnt[idx1] ++;
				switch(cnt[idx1]){
					case 2:		cntPair ++;		break;
					case 3:		isThreeOfAKind = true;	break;
					case 4:		isFourOfAKind = true;
				}
			}
			for(int idx = 0; idx < 4; idx ++)
				if(suit[idx] == 5)		isFlush = true;
			for(int idx1 = 2; idx1 + 5 < 16; idx1 ++){
				int combo = 0;
				for(int idx2 = idx1; idx2 < idx1 + 5; idx2 ++)
					if(cnt[idx2])	combo ++;
				if(combo == 5)		isStraight = true;
			}
			if(isStraight && isFlush)		val[turn] = 9;
			else if(isFourOfAKind)			val[turn] = 8;
			else if(isThreeOfAKind && cntPair)	val[turn] = 7;
			else if(isFlush)			val[turn] = 6;
			else if(isStraight)			val[turn] = 5;
			else if(isThreeOfAKind)			val[turn] = 4;
			else if(cntPair == 2)			val[turn] = 3;
			else if(cntPair)			val[turn] = 2;
			else					val[turn] = 1;
		}
		if(val[0] > val[1])			ans ++;
		else if(val[0] == val[1])
			switch(val[0]){
				case 1:	case 5:	case 6:	case 9:
					sort(player[0], player[0] + 5, cmpHighCard),
					sort(player[1], player[1] + 5, cmpHighCard);
					for(int idx = 0; idx < 5; idx ++)
						if(player[0][idx].first > player[1][idx].first){	ans ++;		break;		}
						else if(player[0][idx].first < player[1][idx].first)			break;
					break;
				case 2:
					for(int idx1 = 0; idx1 < 5; idx1 ++)
						for(int idx2 = idx1 + 1; idx2 < 5; idx2 ++){
							if(player[0][idx1].first == player[0][idx2].first)
								swap(player[0][idx1], player[0][0]),
								swap(player[0][idx2], player[0][1]);
							if(player[1][idx1].first == player[1][idx2].first)
								swap(player[1][idx1], player[1][0]),
								swap(player[1][idx2], player[1][1]);
						}
					sort(player[0] + 2, player[0] + 5, cmpHighCard),
					sort(player[1] + 2, player[1] + 5, cmpHighCard);
					if(player[0][0].first > player[1][0].first)		ans ++;
					else if(player[0][0].first == player[1][0].first)
						for(int idx = 2; idx < 5; idx ++)
							if(player[0][idx].first > player[1][idx].first){	ans ++;		break;		}
							else if(player[0][idx].first < player[1][idx].first)			break;
					break;
				case 3:
					for(int idx1 = 0, base1 = 0, base2 = 0; idx1 < 5; idx1 ++)
						for(int idx2 = idx1 + 1; idx2 < 5; idx2 ++){
							if(player[0][idx1].first == player[0][idx2].first)
								swap(player[0][idx1], player[0][base1 ++]),
								swap(player[0][idx2], player[0][base1 ++]);
							if(player[1][idx1].first == player[1][idx2].first)
								swap(player[1][idx1], player[1][base2 ++]),
								swap(player[1][idx2], player[1][base2 ++]);
						}
					sort(player[0], player[0] + 4, cmpHighCard),
					sort(player[1], player[1] + 4, cmpHighCard);
					if(player[0][0].first > player[1][0].first)		ans ++;
					else if(player[0][0].first == player[1][0].first)
						if(player[0][2].first > player[1][2].first)		ans ++;
						else if(player[0][2].first == player[1][2].first)
							if(player[0][4].first > player[1][4].first)		ans ++;
					break;
				case 4:	case 7:
					for(int idx1 = 0; idx1 < 5; idx1 ++)
						for(int idx2 = idx1 + 1; idx2 < 5; idx2 ++)
							for(int idx3 = idx2 + 1; idx3 < 5; idx3 ++){
								if(player[0][idx1].first == player[0][idx2].first
								&& player[0][idx2].first == player[0][idx3].first)
									swap(player[0][idx1], player[0][0]),
									swap(player[0][idx2], player[0][1]),
									swap(player[0][idx3], player[0][2]);
								if(player[1][idx1].first == player[1][idx2].first
								&& player[1][idx2].first == player[1][idx3].first)
									swap(player[1][idx1], player[1][0]),
									swap(player[1][idx2], player[1][1]),
									swap(player[1][idx3], player[1][2]);
							}
					if(player[0][0].first > player[1][0].first)		ans ++;
					break;
				case 8:
					for(int idx1 = 0; idx1 < 5; idx1 ++)
						for(int idx2 = idx1 + 1; idx2 < 5; idx2 ++)
							for(int idx3 = idx2 + 1; idx3 < 5; idx3 ++)
								for(int idx4 = idx3 + 1; idx4 < 5; idx4 ++){
									if(player[0][idx1].first == player[0][idx2].first
									&& player[0][idx2].first == player[0][idx3].first
									&& player[0][idx3].first == player[0][idx4].first)
										swap(player[0][idx1], player[0][0]),
										swap(player[0][idx2], player[0][1]),
										swap(player[0][idx3], player[0][2]),
										swap(player[0][idx4], player[0][3]);
									if(player[1][idx1].first == player[1][idx2].first
									&& player[1][idx2].first == player[1][idx3].first
									&& player[1][idx3].first == player[1][idx4].first)
										swap(player[1][idx1], player[1][0]),
										swap(player[1][idx2], player[1][1]),
										swap(player[1][idx3], player[1][2]),
										swap(player[1][idx4], player[1][3]);
								}
					if(player[0][0].first > player[1][0].first)		ans ++;
					break;
			}
	}
	cout << ans;
	return 0;
}
//	Title:	Problem 54 - Poker hands
//	URL:	https://projecteuler.net/problem=54
//	Time:	O(?)
//	Input:	P54.txt
//	Output:	376
//	Lang:	C++
