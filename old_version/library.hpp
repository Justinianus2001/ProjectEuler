/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#pragma once

#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

/* REDEFINED CONSTANT   ======================================================================== */

#define LLONG_MAX		9223372036854775807
#define INT_MAX 		2147483647
#define DBL_MAX		 	1.79769e+308

/* DEFINED CONSTANT   ========================================================================== */

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1
#define PHI				1.61803398875
#define EULER			2.71828182846

/* REDEFINED FUNCTION   ======================================================================== */

inline long long accumulate(set<long long>::iterator begin, set<long long>::iterator end, long long sum) {
	while (begin != end) {
		sum += *begin ++;
	}
	return sum;
}

inline long long accumulate(vector<long long>::iterator begin, vector<long long>::iterator end, long long sum) {
	while (begin != end) {
		sum += *begin ++;
	}
	return sum;
}

inline void advance(vector<long long>::iterator &it, long long dis) {
	it += dis;
}

//inline vector<long long>::iterator begin(vector<long long> vec) {
//	return vec.begin();
//}

inline long double cbrt(long double num) {
	long double prev = 0, res = num;
	while (res != prev) {
		prev = res;
		res = (num / prev + prev) / 3;
	}
	return res;
}

inline long long ceil(long double num) {
	long long numLL = (long long) num;
	return numLL + (num > numLL);
}

inline long long count(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	long long res = 0;
	while (begin != end) {
		if (*begin ++ == val) {
			res ++;
		}
	}
	return res;
}

inline long long distance(vector<long long>::iterator begin, vector<long long>::iterator end) {
	return end - begin;
}

//inline vector<long long>::iterator end(vector<long long> vec) {
//	return vec.end();
//}

inline void fill(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	while (begin != end) {
		*begin ++ = val;
	}
}

inline vector<long long>::iterator find(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	while (begin != end) {
		if (*begin == val) {
			return begin;
		}
		begin ++;
	}
	return end;
}

inline long long __gcd(long long lhs, long long rhs) {
	return !rhs ? lhs : __gcd(rhs, lhs % rhs);
}

inline pair<vector<long long>::iterator, vector<long long>::iterator> mismatch(vector<long long>::iterator begin1, vector<long long>::iterator end1, vector<long long>::iterator begin2) {
	while (begin1 != end1 && *begin1 == *begin2) {
		begin1 ++;
		begin2 ++;
	}
	return {begin1, begin2};
}

inline void iota(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	while (begin != end) {
		*begin ++ = val ++;
	}
}

inline bool is_permutation(vector<long long>::iterator begin1, vector<long long>::iterator end1, vector<long long>::iterator begin2) {
	tie(begin1, begin2) = mismatch(begin1, end1, begin2);
	if (begin1 == end1) {
		return true;
	}
	vector<long long>::iterator end2 = begin2;
	advance(end2, distance(begin1, end1));
	for (vector<long long>::iterator it = begin1; it != end1; it ++) {
		if (find(begin1, it, *it) == it) {
			long long cnt = count(begin2, end2, *it);
			if (!cnt || count(it, end1, *it) != cnt) {
				return false;
			}
		}
	}
	return true;
}

inline bool isalpha(char ch) {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

inline bool isdigit(char ch) {
	return ch >= '0' && ch <= '9';
}

inline bool isalnum(char ch) {
	return isalpha(ch) || isdigit(ch);
}

inline bool isspace(char ch) {
	string space = " \t\n\v\f\r";
	return space.find(ch) != string::npos;
}

inline void iter_swap(vector<long long>::iterator lhs, vector<long long>::iterator rhs) {
	long long temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

inline void iter_swap(vector<string>::iterator lhs, vector<string>::iterator rhs) {
	string temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

inline long long log10(long long num) {
	long long res = 0;
	do {
		num /= 10;
		res ++;
	} while (num);
	return res;
}

inline vector<long long>::iterator lower_bound(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	vector<long long>::iterator it;
	iterator_traits<vector<long long>::iterator>::difference_type cnt = distance(begin, end), step;
	while (cnt) {
		it = begin;
		step = cnt / 2;
		advance(it, step);
		if (*it < val) {
			begin = ++ it;
			cnt -= step + 1;
		} else {
			cnt = step;
		}
	}
	return begin;
}

inline bool binary_search(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	begin = lower_bound(begin, end, val);
	return begin != end && *begin == val;
}

inline long long max(long long lhs, long long rhs) {
	return lhs > rhs ? lhs : rhs;
}

inline vector<long long>::iterator max_element(vector<long long>::iterator begin, vector<long long>::iterator end) {
	if (begin == end) {
		return end;
	}
	vector<long long>::iterator res = begin;
	while (++ begin != end) {
		if (*begin > *res) {
			res = begin;
		}
	}
	return res;
}

inline long long min(long long lhs, long long rhs) {
	return lhs < rhs ? lhs : rhs;
}

inline vector<long long>::iterator min_element(vector<long long>::iterator begin, vector<long long>::iterator end) {
	if (begin == end) {
		return end;
	}
	vector<long long>::iterator res = begin;
	while (++ begin != end) {
		if (*begin < *res) {
			res = begin;
		}
	}
	return res;
}

inline long long pow(long long base, long long exp) {
	long long res = 1;
	while (exp) {
		if (exp & 1) {
			res *= base;
		}
		base *= base;
		exp >>= 1;
	}
	return res;
}

inline long double powl(long double base, long long exp) {
	long double res = 1;
	while (exp) {
		if (exp & 1) {
			res *= base;
		}
		base *= base;
		exp >>= 1;
	}
	return res;
}

inline void swap(long long &lhs, long long &rhs) {
	lhs = lhs ^ rhs;
	rhs = lhs ^ rhs;
	lhs = lhs ^ rhs;
}

inline void random_shuffle(vector<long long>::iterator begin, vector<long long>::iterator end) {
	iterator_traits<vector<long long>::iterator>::difference_type cnt = distance(begin, end), step = cnt - 1;
	while (step --) {
		swap(begin[step], begin[rand() % (step + 1)]);
	}
}

inline vector<long long>::iterator remove(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	vector<long long>::iterator res = begin;
	while (begin != end) {
		if (*begin != val) {
			if (res != begin) {
				*res = move(*begin);
			}
			res ++;
		}
		begin ++;
	}
	return res;
}

inline void reverse(vector<long long>::iterator begin, vector<long long>::iterator end) {
	while (begin != end && begin != -- end) {
		iter_swap(begin ++, end);
	}
}

inline void rotate(vector<long long>::iterator begin, vector<long long>::iterator middle, vector<long long>::iterator end) {
	vector<long long>::iterator next = middle;
	while (begin != next) {
		swap(*begin ++, *next ++);
		if (next == end) {
			next = middle;
		} else if (begin == middle) {
			middle = next;
		}
	}
}

inline bool next_permutation(vector<long long>::iterator begin, vector<long long>::iterator end) {
	if (begin == end || begin + 1 == end) {
		return false;
	}
	vector<long long>::iterator first = end - 1, second, third;
	while (true) {
		second = first --;
		if (*first < *second) {
			third = end;
			while (!(*first < *-- third));
			iter_swap(first, third);
			reverse(second, end);
			return true;
		}
		if (first == begin) {
			reverse(begin, end);
			return false;
		}
	}
}

inline bool prev_permutation(vector<long long>::iterator begin, vector<long long>::iterator end) {
	if (begin == end || begin + 1 == end) {
		return false;
	}
	vector<long long>::iterator first = end - 1, second, third;
	while (true) {
		second = first --;
		if (*first > *second) {
			third = end;
			while (!(*first > *-- third));
			iter_swap(first, third);
			reverse(second, end);
			return true;
		}
		if (first == begin) {
			reverse(begin, end);
			return false;
		}
	}
}

inline long double sqrt(long double num) {
	long double prev = 0, res = num;
	while (res != prev) {
		prev = res;
		res = (num / prev + prev) / 2;
	}
	return res;
}

inline long long stoi(char ch) {
	return ch - '0';
}

inline long long stoll(char *str) {
	long long res = 0;
	for (long long idx = 0; str[idx] != '\0'; idx ++) {
		res = res * 10 + stoi(str[idx]);
	}
	return res;
}

inline char tolower(char ch) {
	return ch >= 'A' && ch <= 'Z' ? ch + 32 : ch;
}

//inline string to_string(long long num) {
//	string res;
//	bool neg = false;
//	if (num < 0) {
//		neg = true;
//		num = - num;
//	}
//	do {
//		res += (num % 10) + '0';
//		num /= 10;
//	} while (num);
//	reverse(begin(res), end(res));
//	if (neg) {
//		res = '-' + res;
//	}
//	return res;
//}

inline vector<long long>::iterator upper_bound(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	vector<long long>::iterator it;
	iterator_traits<vector<long long>::iterator>::difference_type cnt = distance(begin, end), step;
	while (cnt) {
		it = begin;
		step = cnt / 2;
		advance(it, step);
		if (*it <= val) {
			begin = ++ it;
			cnt -= step + 1;
		} else {
			cnt = step;
		}
	}
	return begin;
}

/* DEFINED FUNCTION   ========================================================================== */

inline long long binary_search_getPos(vector<long long>::iterator begin, vector<long long>::iterator end, long long val) {
	vector<long long>::iterator pos = lower_bound(begin, end, val);
	return pos != end && *pos == val ? pos - begin : end - begin;
}

inline pair<long long, long long> card2Pair(string card) {
	pair<long long, long long> res;
	switch (card[0]) {
		case 'A':
			res.first = 14;
			break;
		case 'K':
			res.first = 13;
			break;
		case 'Q':
			res.first = 12;
			break;
		case 'J':
			res.first = 11;
			break;
		case 'T':
			res.first = 10;
			break;
		default:
			res.first = card[0] - '0';
	}
	switch (card[1]) {
		case 'S':
			res.second = 0;
			break;
		case 'C':
			res.second = 1;
			break;
		case 'D':
			res.second = 2;
			break;
		case 'H':
			res.second = 3;
	}
	return res;
}

inline bool cmpHighCard(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	sort(begin(hand1), end(hand1), greater<pair<long long, long long>>());
	sort(begin(hand2), end(hand2), greater<pair<long long, long long>>());
	for (long long idx = 0; idx < hand1.size(); idx ++) {
		if (hand1[idx].first != hand2[idx].first) {
			return hand1[idx].first > hand2[idx].first;
		}
	}
	return false;
}

inline bool cmpOnePair(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	sort(begin(hand1), end(hand1), greater<pair<long long, long long>>());
	sort(begin(hand2), end(hand2), greater<pair<long long, long long>>());
	vector<pair<long long, long long>> high[2];
	long long pair[2];
	for (long long idx = 0; idx < 5; idx ++) {
		if (idx < 4 && hand1[idx].first == hand1[idx + 1].first) {
			pair[0] = hand1[idx ++].first;
		} else {
			high[0].push_back(hand1[idx]);
		}
	}
	for (long long idx = 0; idx < 5; idx ++) {
		if (idx < 4 && hand2[idx].first == hand2[idx + 1].first) {
			pair[1] = hand2[idx ++].first;
		} else {
			high[1].push_back(hand2[idx]);
		}
	}
	return pair[0] > pair[1] || (pair[0] == pair[1] && cmpHighCard(high[0], high[1]));
}

inline bool cmpTwoPairs(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	sort(begin(hand1), end(hand1), greater<pair<long long, long long>>());
	sort(begin(hand2), end(hand2), greater<pair<long long, long long>>());
	vector<pair<long long, long long>> high[2];
	long long pair[2][2];
	for (long long idx = 0, stt = 0; idx < 5; idx ++) {
		if (idx < 4 && hand1[idx].first == hand1[idx + 1].first) {
			pair[0][stt ++] = hand1[idx ++].first;
		} else {
			high[0].push_back(hand1[idx]);
		}
	}
	for (long long idx = 0, stt = 0 ; idx < 5; idx ++) {
		if (idx < 4 && hand2[idx].first == hand2[idx + 1].first) {
			pair[1][stt ++] = hand2[idx ++].first;
		} else {
			high[1].push_back(hand2[idx]);
		}
	}
	return pair[0][0] > pair[1][0] || (pair[0][0] == pair[1][0] && pair[0][1] > pair[1][1]) || (pair[0][0] == pair[1][0] && pair[0][1] == pair[1][1] && cmpHighCard(high[0], high[1]));
}

inline bool cmpThreeOfAKind(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	sort(begin(hand1), end(hand1), greater<pair<long long, long long>>());
	sort(begin(hand2), end(hand2), greater<pair<long long, long long>>());
	long long triple[2];
	for (long long idx = 0; idx < 3; idx ++) {
		if (hand1[idx].first == hand1[idx + 1].first && hand1[idx].first == hand1[idx + 2].first) {
			triple[0] = hand1[idx].first;
		}
		if (hand2[idx].first == hand2[idx + 1].first && hand2[idx].first == hand2[idx + 2].first) {
			triple[1] = hand2[idx].first;
		}
	}
	return triple[0] > triple[1];
}

inline bool cmpStraight(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	sort(begin(hand1), end(hand1), greater<pair<long long, long long>>());
	sort(begin(hand2), end(hand2), greater<pair<long long, long long>>());
	return hand1[0].first > hand2[0].first;
}

inline bool cmpFlush(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	sort(begin(hand1), end(hand1), greater<pair<long long, long long>>());
	sort(begin(hand2), end(hand2), greater<pair<long long, long long>>());
	for (long long idx = 0; idx < 5; idx ++) {
		if (hand1[idx].first != hand2[idx].first) {
			return hand1[idx].first > hand2[idx].first;
		}
	}
	return false;
}

inline bool cmpFullHouse(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	return cmpThreeOfAKind(hand1, hand2);
}

inline bool cmpFourOfAKind(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	sort(begin(hand1), end(hand1), greater<pair<long long, long long>>());
	sort(begin(hand2), end(hand2), greater<pair<long long, long long>>());
	long long quadra[2];
	for (long long idx = 0; idx < 2; idx ++) {
		if (hand1[idx].first == hand1[idx + 1].first && hand1[idx].first == hand1[idx + 2].first && hand1[idx].first == hand1[idx + 3].first) {
			quadra[0] = hand1[idx].first;
		}
		if (hand2[idx].first == hand2[idx + 1].first && hand2[idx].first == hand2[idx + 2].first && hand1[idx].first == hand1[idx + 3].first) {
			quadra[1] = hand2[idx].first;
		}
	}
	return quadra[0] > quadra[1];
}

inline bool cmpStraightFlush(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	return cmpStraight(hand1, hand2);
}

inline bool cmpRoyalFlush(vector<pair<long long, long long>> hand1, vector<pair<long long, long long>> hand2) {
	return false;
}

inline long long cntDiv(long long num) {
	long long res = 0;
	for (long long div = 1; div * div <= num; div ++) {
		if(!(num % div)) {
			res += 2 - (div * div == num);
		}
	}
	return res;
}

inline long long cntDiv(long long num, vector<long long> primes) {
	long long D = 1, exp, rem = num;
	for (long long idx = 0; idx < primes.size() && rem != 1; idx ++) {
		if (primes[idx] * primes[idx] > rem) {
			return D * 2;
		}
		exp = 1;
		while (!(rem % primes[idx])) {
			rem /= primes[idx];
			exp ++;
		}
		D *= exp;
	}
	return D;
}

inline long long concat(long long lhs, long long rhs) {
	return lhs * pow(10LL, log10(rhs)) + rhs;
}

inline string dec2Bin(long long num) {
	string res;
	do {
		res += (num % 2) + '0';
		num /= 2;
	} while (num);
	reverse(begin(res), end(res));
	return res;
}

inline bool isLeapYear(long long year) {
	return (!(year % 4) && year % 100) || !(year % 400);
}

inline long long daysOfMonth(long long month, long long year) {
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return 28 + isLeapYear(year);
	}
	return -1;
}

inline long long getNumDigit(long long num, long long idx) {
	long long len = log10(num);
	while (len -- > idx) {
		num /= 10;
	}
	return num % 10;
}

inline long long getChampernowneDigit(long long idx) {
	long long range = 9, digits = 1, res = 0;
	while (idx >= range * digits) {
		res += range;
		idx -= range * digits;
		range *= 10;
		digits ++;
	}
	res += idx / digits;
	idx %= digits;
	if (!idx) {
		return res % 10;
	}
	return getNumDigit(res + 1, idx);
}

inline long long getCharIdx(char ch) {
	return tolower(ch) - 'a' + 1;
}

inline long long getDayOfWeek(long long year, long long month, long long day) {
	if (month <= 2) {
		month += 12;
		year --;
	}
	return (day + 13 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}

inline long long getFact(long long fact) {
	long long res = 1;
	for (long long num = 2; num <= fact; num ++)
		res *= num;
	return res;
}

inline long long getNum(vector<long long> vec) {
	long long res = 0;
	for (long long digit: vec) {
		res = res * 10 + digit;
	}
	return res;
}

//inline long double getNthRoot(long double num, long long root) {
//	long double prev = 0, res = num;
//	while (res != prev) {
//		cout << res << ' ';
//		prev = res;
//		res = (num / prev + prev) / root;
//	}
//	return res;
//}

inline long long getTriangularVal(long long idx) {
	long long val1 = idx, val2 = idx + 1;
	!(val1 % 2) ? val1 /= 2 : val2 /= 2;
	return val1 * val2;
}

inline long long getSquareVal(long long idx) {
	return idx * idx;
}

inline long long getPentagonalVal(long long idx) {
	long long val1 = idx, val2 = idx * 3 - 1;
	!(val1 % 2) ? val1 /= 2 : val2 /= 2;
	return val1 * val2;
}

inline long long getHexagonalVal(long long idx) {
	long long val1 = idx, val2 = idx * 2 - 1;
	return val1 * val2;
}

inline long long getHeptagonalVal(long long idx) {
	long long val1 = idx, val2 = idx * 5 - 3;
	!(val1 % 2) ? val1 /= 2 : val2 /= 2;
	return val1 * val2;
}

inline long long getOctagonalVal(long long idx) {
	long long val1 = idx, val2 = idx * 3 - 2;
	return val1 * val2;
}

inline long long getCubeVal(long long idx) {
	return idx * idx * idx;
}

inline vector<long long> getVector(long long num) {
	vector<long long> res;
	while (num) {
		res.push_back(num % 10);
		num /= 10;
	}
	reverse(begin(res), end(res));
	return res;
}

inline bool isPalindrome(long long num) {
	long long revNum = 0, Num = num;
	while (Num) {
		revNum = revNum * 10 + Num % 10;
		Num /= 10;
	}
	return num == revNum;
}

inline bool isPalindrome(string str) {
	for (long long idx = 0; idx < str.length() / 2; idx ++) {
		if (str[idx] != str[str.length() - idx - 1]) {
			return false;
		}
	}
	return true;
}

inline bool isPermutation(long long lhs, long long rhs) {
	string Lhs = to_string(lhs), Rhs = to_string(rhs);
	sort(begin(Lhs), end(Lhs));
	sort(begin(Rhs), end(Rhs));
	return Lhs == Rhs;
}

inline bool isPrime(long long num) {
	if (num == 2 || num == 3) {
		return true;
	}
	if (num <= 1 || !(num % 2) || !(num % 3)) {
		return false;
	}
	for (long long div = 5; div * div <= num; div += 6) {
		if (!(num % div) || !(num % (div + 2))) {
			return false;
		}
	}
	return true;
}

inline bool isTriangularVal(long long val) {
	long long idx = sqrt(val) * sqrt(2LL);
	return getTriangularVal(idx) == val;
}

inline bool isSquareVal(long long val) {
	long long idx = sqrt(val);
	return getSquareVal(idx) == val;
}

inline bool isPentagonalVal(long long val) {
	long long idx = (sqrt(val * 24 + 1) + 1) / 6;
	return getPentagonalVal(idx) == val;
}

inline bool isHexagonalVal(long long val) {
	long long idx = (sqrt(val * 8 + 1) + 1) / 4;
	return getHexagonalVal(idx) == val;
}

inline bool isHeptagonalVal(long long val) {
	long long idx = (sqrt(val * 40 + 9) + 3) / 10;
	return getHeptagonalVal(idx) == val;
}

inline bool isOctagonalVal(long long val) {
	long long idx = (sqrt(val * 12 + 4) + 2) / 6;
	return getOctagonalVal(idx) == val;
}

inline bool isCubeVal(long long val) {
	long long idx = cbrt(val);
	return getCubeVal(idx) == val;
}

inline bool isHighCard(vector<pair<long long, long long>> hand) {
	return !!hand.size();
}

inline bool isOnePair(vector<pair<long long, long long>> hand) {
	long long *cache = new long long[15](), cntPair = 0;
	for (pair<long long, long long> card: hand) {
		cache[card.first] ++;
	}
	for (long long val = 2; val < 15; val ++) {
		if (cache[val] == 2) {
			cntPair ++;
		}
	}
	return cntPair == 1;
}

inline bool isTwoPairs(vector<pair<long long, long long>> hand) {
	long long *cache = new long long[15](), cntPair = 0;
	for (pair<long long, long long> card: hand) {
		cache[card.first] ++;
	}
	for (long long val = 2; val < 15; val ++) {
		if (cache[val] == 2) {
			cntPair ++;
		}
	}
	return cntPair == 2;
}

inline bool isThreeOfAKind(vector<pair<long long, long long>> hand) {
	long long *cache = new long long[15]();
	for (pair<long long, long long> card: hand) {
		cache[card.first] ++;
	}
	for (long long val = 2; val < 15; val ++) {
		if (cache[val] == 3) {
			return true;
		}
	}
	return false;
}

inline bool isStraight(vector<pair<long long, long long>> hand) {
	long long *cache = new long long[15]();
	for (pair<long long, long long> card: hand) {
		cache[card.first] ++;
	}
	for (long long val = 2; val < 11; val ++) {
		if (cache[val] && cache[val + 1] && cache[val + 2] && cache[val + 3] && cache[val + 4]) {
			return true;
		}
	}
	return false;
}

inline bool isFlush(vector<pair<long long, long long>> hand) {
	long long *cache = new long long[4](), cntSuit = 0;
	for (pair<long long, long long> card: hand) {
		cache[card.second] ++;
	}
	for (long long suit = 0; suit < 4; suit ++) {
		cntSuit += !!cache[suit];
	}
	return cntSuit == 1;
}

inline bool isFullHouse(vector<pair<long long, long long>> hand) {
	return isOnePair(hand) && isThreeOfAKind(hand);
}

inline bool isFourOfAKind(vector<pair<long long, long long>> hand) {
	long long *cache = new long long[15]();
	for (pair<long long, long long> card: hand) {
		cache[card.first] ++;
	}
	for (long long val = 2; val < 15; val ++) {
		if (cache[val] == 4) {
			return true;
		}
	}
	return false;
}

inline bool isStraightFlush(vector<pair<long long, long long>> hand) {
	return isStraight(hand) && isFlush(hand);
}

inline bool isRoyalFlush(vector<pair<long long, long long>> hand) {
	long long *cache = new long long[15]();
	for (pair<long long, long long> card: hand) {
		cache[card.first] ++;
	}
	return isStraightFlush(hand) && cache[14];
}

vector<pair<string, long long>> romanNumeral =
	{{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
inline string num2Roman(long long num) {
	string res;
	for (pair<string, long long> roman: romanNumeral) {
		while (roman.second <= num) {
			res += roman.first;
			num -= roman.second;
		}
	}
	return res;
}

inline long long roman2Num(string roman) {
	long long res = 0;
	for (long long idx = 0; idx < roman.length(); ) {
		for (pair<string, long long> num: romanNumeral) {
			if (idx + num.first.length() <= roman.length() && roman.substr(idx, num.first.length()) == num.first) {
				res += num.second;
				idx += num.first.length();
				break;
			}
		}
	}
	return res;
}

inline long long powMod(long long base, long long exp, long long mod) {
	long long res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

//	Old version
//vector<long long> primes = {};
//inline void sieve(long long range) {
//	bool ok;
//	for (long long num = 2; num <= range; num += 1 + (num != 2)) {
//		ok = true;
//		for (long long prime: primes) {
//			if (prime * prime > num) {
//				break;
//			}
//			if (!(num % prime)) {
//				ok = false;
//				break;
//			}
//		}
//		if (ok) {
//			primes.push_back(num);
//		}
//	}
//}

vector<long long> primes = {};
inline void sieve(long long range) {
	primes.clear();
	long long *factor = new long long[range + 3]();
	for(long long num = 2; num <= range; num ++) {
		if(!factor[num])
			primes.push_back(num), factor[num] = num;
		for(long long mul = 0; mul < primes.size() && num * primes[mul] <= range && primes[mul] <= factor[num]; mul ++)
			factor[num * primes[mul]] = primes[mul];
	}
}

vector<long long> mapDiv = {};
inline void sieveCntDiv(long long range) {
	mapDiv.resize(range);
	fill(begin(mapDiv), end(mapDiv), 0LL);
	for(long long num = 2; num <= range; num += (num != 2) + 1)
		if(!mapDiv[num])
			for(long long mul = num; mul <= range; mul += num)
				mapDiv[mul] ++;
}

vector<long long> primesSegment = {};
inline void sieveSegment(long long begin, long long end) {
	primesSegment.clear();
	vector<bool> ok(end - begin + 1, true);
	for (long long div = 2; div * div <= end; div ++) {
		for (long long num = max(div * div, (begin + div - 1) / div * div); num <= end; num += div) {
			ok[num - begin] = false;
		}
	}
	for (long long num = begin; num <= end; num ++) {
		if (ok[num - begin]) {
			primesSegment.push_back(num);
		}
	}
}

vector<long long> mapSumDiv = {};
inline void sieveSumDiv(long long range) {
	mapSumDiv.resize(range);
	fill(begin(mapSumDiv), end(mapSumDiv), 0LL);
	sieve(range);
	for (long long num = 2; num <= range; num ++) {
		long long rem = num;
		mapSumDiv[num] = 1;
		for (long long prime: primes) {
			if (prime * prime > rem) {
				break;
			}
			long long factor = 1;
			while (!(rem % prime)) {
				rem /= prime;
				factor = factor * prime + 1;
			}
			mapSumDiv[num] *= factor;
		}
		if (rem > 1 && rem < num) {
			mapSumDiv[num] *= rem + 1;
		}
		if (mapSumDiv[num] > 1) {
			mapSumDiv[num] -= num;
		}
	}
}

long long sudoku[9][9], resSudoku[9][9];
inline void solveSudoku(long long curRow, long long curCol, bool square[3][3][10], bool row[9][10], bool col[9][10]) {
	if (curRow == 9) {
		for (long long rowIdx = 0; rowIdx < 9; rowIdx ++) {
			for (long long colIdx = 0; colIdx < 9; colIdx ++) {
				resSudoku[rowIdx][colIdx] = sudoku[rowIdx][colIdx];
			}
		}
	} else if (sudoku[curRow][curCol]) {
		solveSudoku(curRow + (curCol == 8), (curCol + 1) % 9, square, row, col);
	} else {
		for (long long num = 1; num < 10; num ++) {
			if (!square[curRow / 3][curCol / 3][num] && !row[curRow][num] && !col[curCol][num]) {
				square[curRow / 3][curCol / 3][num] = row[curRow][num] = col[curCol][num] = true;
				sudoku[curRow][curCol] = num;
				solveSudoku(curRow + (curCol == 8), (curCol + 1) % 9, square, row, col);
				square[curRow / 3][curCol / 3][num] = row[curRow][num] = col[curCol][num] = false;
				sudoku[curRow][curCol] = 0;
			}
		}
	}
}

inline long long sumDiv(long long num) {
	long long res = 1;
	for (long long div = 2; div * div <= num; div ++) {
		if (!(num % div)) {
			res += div;
			if (div * div != num) {
				res += num / div;
			}
		}
	}
	return res;
}

inline long long sumDiv(long long num, vector<long long> primes) {
	long long res = 1, rem = num, powVal;
	for (long long idx = 0; idx < primes.size() && primes[idx] * primes[idx] <= rem && rem > 1; idx ++) {
		if (!(rem % primes[idx])) {
			powVal = primes[idx];
			while (!(rem % primes[idx])) {
				powVal *= primes[idx];
				rem /= primes[idx];
			}
			res = res * (powVal - 1) / (primes[idx] - 1);
		}
	}
	if (rem > 1) {
		res *= rem + 1;
	}
	return res - num;
}

inline long long sumFactDigit(long long num) {
	long long res = 0;
	while (num) {
		res += getFact(num % 10);
		num /= 10;
	}
	return res;
}

inline long long sumMultiplesXBelowN(long long num, long long div) {
	return getTriangularVal(num / div) * div;
}

inline long long sumPowDigit(long long num, long long exp) {
	long long sum = 0;
	while (num) {
		sum += pow(num % 10, exp);
		num /= 10;
	}
	return sum;
}

inline string speak(long long num) {
	string ans;
	if (num >= 1000000000000) {
		ans += speak(num / 1000000000000) + "Trillion";
		num %= 1000000000000;
		if (num && ans.find("And") == string::npos) {
			ans += "And";
		}
	}
	if (num >= 1000000000) {
		ans += speak(num / 1000000000) + "Billion";
		num %= 1000000000;
		if (num && ans.find("And") == string::npos) {
			ans += "And";
		}
	}
	if (num >= 1000000) {
		ans += speak(num / 1000000) + "Milion";
		num %= 1000000;
		if (num && ans.find("And") == string::npos) {
			ans += "And";
		}
	}
	if (num >= 1000) {
		ans += speak(num / 1000) + "Thousand";
		num %= 1000;
		if (num && ans.find("And") == string::npos) {
			ans += "And";
		}
	}
	if (num >= 100) {
		ans += speak(num / 100) + "Hundred";
		num %= 100;
		if (num && ans.find("And") == string::npos) {
			ans += "And";
		}
	}
	if (num >= 20) {
		switch (num / 10) {
			case 2:
				ans += "Twenty";
				break;
			case 3:
				ans += "Thirty";
				break;
			case 4:
				ans += "Forty";
				break;
			case 5:
				ans += "Fifty";
				break;
			case 6:
				ans += "Sixty";
				break;
			case 7:
				ans += "Seventy";
				break;
			case 8:
				ans += "Eighty";
				break;
			case 9:
				ans += "Ninety";
				break;
		}
		num %= 10;
	}
	if (num < 20) {
		switch (num) {
			case 1:
				ans += "One";
				break;
			case 2:
				ans += "Two";
				break;
			case 3:
				ans += "Three";
				break;
			case 4:
				ans += "Four";
				break;
			case 5:
				ans += "Five";
				break;
			case 6:
				ans += "Six";
				break;
			case 7:
				ans += "Seven";
				break;
			case 8:
				ans += "Eight";
				break;
			case 9:
				ans += "Nine";
				break;
			case 10:
				ans += "Ten";
				break;
			case 11:
				ans += "Eleven";
				break;
			case 12:
				ans += "Twelve";
				break;
			case 13:
				ans += "Thirteen";
				break;
			case 14:
				ans += "Fourteen";
				break;
			case 15:
				ans += "Fifteen";
				break;
			case 16:
				ans += "Sixteen";
				break;
			case 17:
				ans += "Seventeen";
				break;
			case 18:
				ans += "Eighteen";
				break;
			case 19:
				ans += "Nineteen";
				break;
		}
		num /= 20;
	}
	return ans;
}

inline vector<string> tokenize(string text, string delim) {
	vector<string> tokens;
	long long begin = text.find_first_not_of(delim), end = 0;
	while ((end = text.find_first_of(delim, begin)) != string::npos) {
		tokens.push_back(text.substr(begin, end - begin));
		begin = text.find_first_not_of(delim, end);
	}
	if (begin != string::npos) {
		tokens.push_back(text.substr(begin));
	}
	return tokens;
}

/* DEFINED TYPE   ============================================================================== */

class bigInteger {
	private:
		vector<long long> bigNum;
		long long log10;
	public:
		bigInteger() {}
		bigInteger(vector<long long> vec) {
			bigNum = vec;
			reverse(begin(bigNum), end(bigNum));
			log10 = vec.size();
		}
		bigInteger(string num) {
			for (char ch: num) {
				bigNum.push_back(stoi(ch));
			}
			reverse(begin(bigNum), end(bigNum));
			log10 = num.length();
		}
		bigInteger(long long num) {
			do {
				bigNum.push_back(num % 10);
				num /= 10;
			} while (num);
			log10 = bigNum.size();
		}
		vector<long long> getBigNum() {
			return bigNum;
		}
		void setBigNum(vector<long long> val) {
			bigNum = val;
		}
		long long getLog10() {
			return log10;
		}
		void setLog10(long long val) {
			log10 = val;
		}
		friend ostream& operator << (ostream& os, bigInteger obj) {
			for (long long idx = obj.log10 - 1; idx >= 0; idx --) {
				os << obj.bigNum[idx];
			}
			return os;
		}
		friend istream& operator >> (istream& is, bigInteger& obj) {
			string str;
			is >> str;
			for (char ch: str) {
				obj.bigNum.push_back(stoi(ch));
			}
			reverse(begin(obj.bigNum), end(obj.bigNum));
			obj.log10 = str.length();
			return is;
		}
		bigInteger operator + (bigInteger obj) {
			long long digit, add = 0;
			bigInteger res;
			for (long long idx = 0; idx < max(log10, obj.log10); idx ++) {
				digit = (idx < log10) * bigNum[idx] + (idx < obj.log10) * obj.bigNum[idx] + add;
				add = digit / 10;
				res.bigNum.push_back(digit % 10);
			}
			if (add) {
				res.bigNum.push_back(add);
			}
			res.log10 = res.bigNum.size();
			return res;
		}
		bigInteger operator * (long long num) {
			long long digit, add = 0;
			bigInteger res;
			for (long long idx = 0; idx < log10; idx ++) {
				digit = bigNum[idx] * num + add;
				add = digit / 10;
				digit %= 10,
				         res.bigNum.push_back(digit);
			}
			while (add) {
				res.bigNum.push_back(add % 10);
				add /= 10;
			}
			res.log10 = res.bigNum.size();
			return res;
		}
		bigInteger operator * (bigInteger num) {
			bigInteger digit, add = 0, res;
			for (long long idx = 0; idx < log10; idx ++) {
				digit = num * bigNum[idx] + add;
				add = digit;
				res.bigNum.push_back(add.bigNum.front());
				add.bigNum.erase(begin(add.bigNum));
				add.log10 --;
			}
			if (add.log10) {
				res.bigNum.insert(end(res.bigNum), begin(add.bigNum), end(add.bigNum));
			}
			res.log10 = res.bigNum.size();
			return res;
		}
		bigInteger& operator = (long long num) {
			do {
				bigNum.push_back(num % 10);
				num /= 10;
			} while (num);
			log10 = bigNum.size();
			return *this;
		}
		bigInteger& operator = (bigInteger obj) {
			bigNum = obj.bigNum;
			log10 = obj.log10;
			return *this;
		}
		bigInteger& operator += (bigInteger obj) {
			*this = *this + obj;
			return *this;
		}
		bigInteger& operator *= (long long num) {
			*this = *this * num;
			return *this;
		}
		bigInteger& operator *= (bigInteger obj) {
			*this = *this * obj;
			return *this;
		}
		bool operator > (bigInteger obj) {
			if (log10 != obj.log10) {
				return log10 > obj.log10;
			}
			for (long long idx = log10 - 1; idx >= 0; idx --) {
				if (bigNum[idx] != obj.bigNum[idx]) {
					return bigNum[idx] > obj.bigNum[idx];
				}
			}
			return false;
		}
		bool operator == (bigInteger obj) {
			if (log10 != obj.log10) {
				return false;
			}
			for (long long idx = log10 - 1; idx >= 0; idx --) {
				if (bigNum[idx] != obj.bigNum[idx]) {
					return false;
				}
			}
			return true;
		}
		bool operator < (bigInteger obj) {
			return !(*this >= obj);
		}
		bool operator >= (bigInteger obj) {
			return *this > obj || *this == obj;
		}
		bool operator <= (bigInteger obj) {
			return *this < obj || *this == obj;
		}
		bigInteger pow(long long exp) {
			bigInteger res = 1, obj = *this;
			while (exp) {
				if (exp & 1) {
					res *= obj;
				}
				obj *= obj;
				exp >>= 1;
			}
			return res;
		}
		long long toInteger() {
			long long res = 0;
			for (long long idx = log10 - 1; idx >= 0; idx --) {
				res = res * 10 + bigNum[idx];
			}
			return res;
		}
		string toString() {
			string res;
			for (long long idx = log10 - 1; idx >= 0; idx --) {
				res += bigNum[idx] + '0';
			}
			return res;
		}
		bigInteger getReverseNum() {
			bigInteger obj = *this;
			reverse(begin(obj.bigNum), end(obj.bigNum));
			while (obj.bigNum.back() == '0' && obj.log10 > 1) {
				obj.bigNum.pop_back();
				obj.log10 --;
			}
			return obj;
		}
};

class fraction {
	private:
		long long numerator, denominator;
	public:
		fraction() {}
		fraction(long long num, long long den) {
			numerator = num;
			denominator = den;
			reduceFraction();
		}
		long long getNumerator() {
			return numerator;
		}
		void setNumerator(long long num) {
			numerator = num;
		}
		long long getDenominator() {
			return denominator;
		}
		void setDenominator(long long den) {
			denominator = den;
		}
		void reduceFraction() {
			long long gcd = __gcd(numerator, denominator);
			if (gcd) {
				numerator /= gcd;
				denominator /= gcd;
			}
		}
		fraction operator + (fraction obj) {
			fraction res;
			res.numerator = numerator * obj.denominator + denominator * obj.numerator;
			res.denominator = denominator * obj.denominator;
			res.reduceFraction();
			return res;
		}
		fraction operator - (fraction obj) {
			fraction res;
			res.numerator = numerator * obj.denominator - denominator * obj.numerator;
			res.denominator = denominator * obj.denominator;
			res.reduceFraction();
			return res;
		}
		fraction operator * (fraction obj) {
			fraction res;
			res.numerator = numerator * obj.numerator;
			res.denominator = denominator * obj.denominator;
			res.reduceFraction();
			return res;
		}
		fraction operator / (fraction obj) {
			fraction res;
			res.numerator = numerator * obj.denominator;
			res.denominator = denominator * obj.numerator;
			res.reduceFraction();
			return res;
		}
		fraction& operator = (fraction obj) {
			numerator = obj.numerator;
			denominator = obj.denominator;
			return *this;
		}
		fraction& operator += (fraction obj) {
			*this = *this + obj;
			return *this;
		}
		fraction& operator -= (fraction obj) {
			*this = *this - obj;
			return *this;
		}
		fraction& operator *= (fraction obj) {
			*this = *this * obj;
			return *this;
		}
		fraction& operator /= (fraction obj) {
			*this = *this / obj;
			return *this;
		}
		bool operator == (fraction obj) {
			return numerator == obj.numerator && denominator == obj.denominator;
		}
		bool operator != (fraction obj) {
			return !(*this == obj);
		}
};

class bigDecimal {
	private:
		long long integer;
		vector<long long> decimal;
		long long decimalSize;
	public:
		bigDecimal() {}
		bigDecimal(long long num) {
			integer = num;
			decimalSize = 0;
		}
		friend ostream& operator << (ostream& os, bigDecimal obj) {
			os << obj.integer;
			if (obj.decimalSize) {
				os << '.';
			}
			for (long long fraction: obj.decimal) {
				os << fraction;
			}
			return os;
		}
		friend istream& operator >> (istream& is, bigDecimal& obj) {
			string str;
			is >> str;
			vector<string> vs = tokenize(str, ".");
			obj.integer = stoll(vs[0]);
			if (vs.size() > 1) {
				for (char ch: vs[1]) {
					obj.decimal.push_back(stoi(ch));
				}
			}
			obj.decimalSize = obj.decimal.size();
			return is;
		}
//		bigDecimal operator / (long long num) {
//			long long add = integer % num, *cache;
//			integer /= num;
//			cache = new long long[num]();
//		}
};

/* NOT SOLVED   ================================================================================ */

/*
 *	Problem 48
 *	Problem 60
 *	Problem 61
 *	Problem 68
 *	Problem 70
 *	Problem 80
 *	Problem 87
 *	Problem 88
 *	Problem 90
 *	Problem 92
 *	Problem 93
 *	Problem 94
 *	Problem 96
 *	Problem 97
 */

#endif
