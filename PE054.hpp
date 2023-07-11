#include <bits/stdc++.h>
using namespace std;

int PE054() {
	freopen("PE054.txt", "r", stdin);
	unordered_map<char, int> val = {{'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5}, {'7', 6}, {'8', 7}, {'9', 8}, {'T', 9}, {'J', 10}, {'Q', 11}, {'K', 12}, {'A', 13}},
		suit = {{'S', 1}, {'C', 2}, {'D', 3}, {'H', 4}};
	int res = 0;
	string s;
	function<bool(vector<pair<int, int>>)> isHighCard = [] (vector<pair<int, int>> hand) {
		return true;
	};
	function<bool(vector<pair<int, int>>)> isOnePair = [] (vector<pair<int, int>> hand) {
		sort(begin(hand), end(hand));
		int cnt = 0;
		for (int i = 1; i < 5; i ++) {
			cnt += hand[i].first == hand[i - 1].first;
		}
		return cnt == 1;
	};
	function<bool(vector<pair<int, int>>)> isTwoPairs = [] (vector<pair<int, int>> hand) {
		sort(begin(hand), end(hand));
		return (hand[0].first == hand[1].first && (hand[2].first == hand[3].first || hand[3].first == hand[4].first))
			|| (hand[1].first == hand[2].first && hand[3].first == hand[4].first);
	};
	function<bool(vector<pair<int, int>>)> isThreeOfAKind = [&] (vector<pair<int, int>> hand) {
		sort(begin(hand), end(hand));
		return hand[0].first == hand[2].first || hand[1].first == hand[3].first || hand[2].first == hand[4].first;
	};
	function<bool(vector<pair<int, int>>)> isStraight = [&] (vector<pair<int, int>> hand) {
		sort(begin(hand), end(hand));
		for (int i = 1; i < 5; i ++) {
			if (hand[i].first != hand[0].first + i) {
				if (i == 4 && hand[i].first - 12 == hand[0].first) {
					continue;
				}
				return false;
			}
		}
		return true;
	};
	function<bool(vector<pair<int, int>>)> isFlush = [&] (vector<pair<int, int>> hand) {
		for (int i = 1; i < 5; i ++) {
			if (hand[i].second != hand[0].second) {
				return false;
			}
		}
		return true;
	};
	function<bool(vector<pair<int, int>>)> isFullHouse = [&] (vector<pair<int, int>> hand) {
		return isThreeOfAKind(hand) && isOnePair(hand);
	};
	function<bool(vector<pair<int, int>>)> isFourOfAKind = [] (vector<pair<int, int>> hand) {
		sort(begin(hand), end(hand));
		return hand[0].first == hand[3].first || hand[1].first == hand[4].first;
	};
	function<bool(vector<pair<int, int>>)> isStraightFlush = [&] (vector<pair<int, int>> hand) {
		return isStraight(hand) && isFlush(hand);
	};
	function<bool(vector<pair<int, int>>, vector<pair<int, int>>)> greaterHighCard = [&] (vector<pair<int, int>> p1, vector<pair<int, int>> p2) {
		sort(begin(p1), end(p1), greater<pair<int, int>>());
		sort(begin(p2), end(p2), greater<pair<int, int>>());
		int len = p1.size();
		for (int i = 0; i < len; i ++) {
			if (p1[i].first > p2[i].first) {
				return true;
			} else if (p1[i].first < p2[i].first) {
				return false;
			}
		}
		return false;
	};
	function<bool(vector<pair<int, int>>, vector<pair<int, int>>)> greaterOnePair = [&] (vector<pair<int, int>> p1, vector<pair<int, int>> p2) {
		sort(begin(p1), end(p1), greater<pair<int, int>>());
		sort(begin(p2), end(p2), greater<pair<int, int>>());
		vector<pair<int, int>> high1, high2;
		int pair1, pair2;
		for (int i = 0; i < 5; i ++) {
			if (high1.size() && p1[i].first == high1.back().first) {
				high1.pop_back();
				pair1 = p1[i].first;
			} else {
				high1.push_back({p1[i].first, 1});
			}
			if (high2.size() && p2[i].first == high2.back().first) {
				high2.pop_back();
				pair2 = p2[i].first;
			} else {
				high2.push_back({p2[i].first, 1});
			}
		}
		if (pair1 > pair2) {
			return true;
		} else if (pair1 == pair2) {
			return greaterHighCard(high1, high2);
		}
		return false;
	};
	while (cin >> s) {
		vector<pair<int, int>> p1 = {{val[s[0]], suit[s[1]]}}, p2;
		for (int i = 1; i < 5; i ++) {
			cin >> s;
			p1.push_back({val[s[0]], suit[s[1]]});
		}
		for (int i = 0; i < 5; i ++) {
			cin >> s;
			p2.push_back({val[s[0]], suit[s[1]]});
		}
		vector<bool> L = {isStraightFlush(p1), isFourOfAKind(p1), isFullHouse(p1), isFlush(p1), isStraight(p1), isThreeOfAKind(p1), isTwoPairs(p1), isOnePair(p1), isHighCard(p1)},
			R = {isStraightFlush(p2), isFourOfAKind(p2), isFullHouse(p2), isFlush(p2), isStraight(p2), isThreeOfAKind(p2), isTwoPairs(p2), isOnePair(p2), isHighCard(p2)};
		for (int i = 0; i < 9; i ++) {
			if (L[i] && R[i]) {
				switch (i) {
					case 7:
						res += greaterOnePair(p1, p2);
						break;
					case 8:
						res += greaterHighCard(p1, p2);
						break;
				}
				break;
			} else if (L[i] || R[i]) {
				res += L[i];
				break;
			}
		}
	}
	cin.clear();
	return res;
}