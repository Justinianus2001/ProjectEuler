#include <bits/stdc++.h>
using namespace std;

int PE086(int num) {
	int cnt = 0;
	for (int width = 1; ; width ++) {
		for (int height = 2; height <= width << 1; height ++) {
			double hypotenuse = hypot(width, height);
			if (hypotenuse == (int)hypotenuse) {
				cnt += height <= width ? height >> 1 : width - (height + 1) / 2 + 1;
			}
		}
		if (cnt >= num) {
			return width;
		}
	}
	return -1;
}