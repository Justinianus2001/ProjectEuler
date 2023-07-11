#include <bits/stdc++.h>
using namespace std;

int PE085(int num) {
	long long width = 1, height = num, res, near = LLONG_MAX;
	while (width <= height) {
		long long area = width * (width + 1) * height * (height + 1) / 4;
		if (abs(area - num) < near) {
			near = abs(area - num);
			res = width * height;
		}
		if (area > num) {
			height --;
		} else {
			width ++;
		}
	}
	return res;
}