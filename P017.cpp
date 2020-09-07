/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include <iostream>
using namespace std;

inline string number(int num){
	string ans;
	if(num >= 1000000000){
		ans = number(num / 1000000000) + "billion";
		num %= 1000000000;
		if (num != 0 && ans.find("a") == string::npos)		ans += "and";
	}
	if(num >= 1000000){
		ans = number(num / 1000000) + "milion";
		num %= 1000000;
		if (num != 0 && ans.find("a") == string::npos)		ans += "and";
	}
	if(num >= 1000){
		ans = number(num / 1000) + "thousand";
		num %= 1000;
		if (num != 0 && ans.find("a") == string::npos)		ans += "and";
	}
	if(num >= 100){
		ans = number(num / 100) + "hundred";
		num %= 100;
		if (num != 0 && ans.find("a") == string::npos)		ans += "and";
	}
	if(num >= 20){
		switch(num / 10){
			case 2:		ans += "twenty";		break;
			case 3:		ans += "thirty";		break;
			case 4:		ans += "forty";			break;
			case 5:		ans += "fifty";			break;
			case 6:		ans += "sixty";			break;
			case 7:		ans += "seventy";		break;
			case 8:		ans += "eighty";		break;
			case 9:		ans += "ninety";		break;
		}
		num %= 10;
	}
	if(num < 20){
		switch(num){
			case 1:		ans += "one";			break;
			case 2:		ans += "two";			break;
			case 3:		ans += "three";			break;
			case 4:		ans += "four";			break;
			case 5:		ans += "five";			break;
			case 6:		ans += "six";			break;
			case 7:		ans += "seven";			break;
			case 8:		ans += "eight";			break;
			case 9:		ans += "nine";			break;
			case 10:	ans += "ten";			break;
			case 11:	ans += "eleven";		break;
			case 12:	ans += "twelve";		break;
			case 13:	ans += "thirteen";		break;
			case 14:	ans += "fourteen";		break;
			case 15:	ans += "fifteen";		break;
			case 16:	ans += "sixteen";		break;
			case 17:	ans += "seventeen";		break;
			case 18:	ans += "eighteen";		break;
			case 19:	ans += "nineteen";		break;
		}
		num /= 20;
	}
	return ans;
}

int main(){
	string ans;
	int num;
	cin >> num;
	for(int i = 1; i <= num; i ++)
		ans += number(i);
	cout << ans.length();
	return 0;
}
//	Title:	Problem 17 - Number letter counts
//	URL:	https://projecteuler.net/problem=17
//	Input:	1000
//	Output:	21124
//	Lang:	C++
