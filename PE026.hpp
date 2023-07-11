#include <bits/stdc++.h>
using namespace std;

int PE026(int num) {
	int res = 0, mx = 0;
	function<int(int, int)> getCycleLen = [] (int num, int deno) {
		int res = 0, tortoise = num * 10 % deno, hare = tortoise * 10 % deno;
		while (tortoise != hare) {
			tortoise = tortoise * 10 % deno;
			hare = (hare * 10 % deno) * 10 % deno;
		}
		tortoise = num % deno;
		while (tortoise != hare) {
			tortoise = tortoise * 10 % deno;
			hare = hare * 10 % deno;
		}
		if (tortoise) {
			do {
				res ++;
				tortoise = tortoise * 10 % deno;
			} while (tortoise != hare);
		}
		return res;
	};
	for (int i = 2; i < num; i ++) {
		int cyc = getCycleLen(1, i);
		if (cyc > mx) {
			mx = cyc;
			res = i;
		}
	}
	return res;
}