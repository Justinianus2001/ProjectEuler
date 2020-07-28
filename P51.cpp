#include <iostream>
#include <vector>
using namespace std;

bool isComposite[1000001];

inline void sieve(int num){
	isComposite[0] = isComposite[1] = true;
	for(int idx1 = 2; idx1 * idx1 <= num; idx1 += (idx1 != 2) + 1)
		if(!isComposite[idx1])
			for(int idx2 = idx1 * idx1; idx2 <= num; idx2 += idx1)
				isComposite[idx2] = true;
}

int main(){
	sieve(1000000);
	string str, copy;
	int inp, ok = 0, cnt;	cin >> inp;
	for(int num = 2; ; num ++)
		if(!isComposite[num]){
			vector<int> lst[10];
			str = to_string(num);
			for(int idx = 0; idx < str.length(); idx ++)
				lst[str[idx] - '0'].push_back(idx);
			for(int digit = 0; digit <= 10 - inp; digit ++){
				if(!lst[digit].size())		continue;
				cnt = 0;
				for(int step = 0; step < 10; step ++){
					copy = str;
					for(auto idx: lst[digit]){
						if(!idx && !step)	goto NEXT;
						copy[idx] = char(step + '0');
					}
					if(!isComposite[stoi(copy)])	cnt ++;
					NEXT:;
				}
				if(cnt == inp){		cout << num;	goto END;	}
			}
		}
	END:;
	return 0;
}
//	Title:	Problem 51 - Prime digit replacements
//	URL:	https://projecteuler.net/problem=51
//	Time:	O(?)
//	Input:	8
//	Output:	121313
//	Lang:	C++
