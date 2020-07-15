#include <iostream>
using namespace std;

inline bool isLeapYear(int year){
	return (!(year % 4) && year % 100) || !(year % 400);
}

int main(){
	int valid[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		dayBegin, dayEnd, monthBegin, monthEnd, yearBegin, yearEnd, weekDay = 2, cnt = 0, flag = 0;
	cin >> dayBegin >> monthBegin >> yearBegin >> dayEnd >> monthEnd >> yearEnd;
	for(int day = 1, month = 1, year = 1900; ; day ++, weekDay ++){
		if(day > valid[month] + (month == 2 && isLeapYear(year)))			day = 1, month ++;
		if(month > 12)														month = 1, year ++;
		if(weekDay > 8)														weekDay -= 7;
		if(day == dayBegin && month == monthBegin && year == yearBegin)		flag = 1;
		if(flag != 1)														continue;
		if(day == 1 && weekDay == 8)										cnt ++;
		if(day == dayEnd && month == monthEnd && year == yearEnd)			break;
	}
	cout << cnt;
	return 0;
}
//	Title:	Problem 19 - Counting Sundays
//	URL:	https://projecteuler.net/problem=19
//	Time:	O(n)
//	Input:	1 1 1901
//			31 12 2000
//	Output:	171
//	Lang:	C++
