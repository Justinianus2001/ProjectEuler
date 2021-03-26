/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	long long monthBegin, monthEnd,
		yearBegin, yearEnd, cntSunday = 0;
	cin >> yearBegin >> monthBegin,
	cin >> yearEnd >> monthEnd;
	for(long long curMonth = monthBegin, curYear = yearBegin;
			curMonth < monthEnd || curYear < yearEnd; curMonth ++){
		if(curMonth > 12)	curMonth = 1, curYear ++;
		cntSunday += getDayOfWeek(curYear, curMonth, 1) == 1;
	}
	cout << cntSunday;
	return EXIT_SUCCESS;
}
//	Title:	Problem 19 - Counting Sundays
//	URL:	https://projecteuler.net/problem=19
//	Input:	1901 1
//		2000 12
//	Output:	171
//	Lang:	C++
