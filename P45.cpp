#include <iostream>
using namespace std;

inline long long getTriangleVal(long long num){
	return num * (num + 1) / 2;
}

inline long long getPentagonVal(long long num){
	return num * (num * 3 - 1) / 2;
}

inline long long getHexagonVal(long long num){
	return num * (num * 2 - 1);
}

int main(){
	long long inp;		cin >> inp;
	for(long long idx1 = inp + 1, idx2 = inp + 1, idx3 = inp + 1; ; idx3 ++){
		while(getTriangleVal(idx1) < getHexagonVal(idx3))	idx1 ++;
		while(getPentagonVal(idx2) < getHexagonVal(idx3))	idx2 ++;
		if(getTriangleVal(idx1) == getPentagonVal(idx2) && getPentagonVal(idx2) == getHexagonVal(idx3)){
			cout << getHexagonVal(idx3);	break;
		}
	}
	return 0;
}
//	Title:	Problem 45 - Triangular, pentagonal, and hexagonal
//	URL:	https://projecteuler.net/problem=45
//	Time:	O(?)
//	Input:	143
//	Output:	1533776805
//	Lang:	C++
