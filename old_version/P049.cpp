/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	map<long long, bool> mp;
	long long len;		cin >> len;
	for(long long num = pow(10LL, len - 1) + 1; num < pow(10, len); num += 2)
		if(isPrime(num) && !mp[num]){
			vector<long long> lst = {num};
			string str = to_string(num);
			while(next_permutation(begin(str), end(str)))
				if(isPrime(stoll(str)))	lst.push_back(stoll(str));
			sort(begin(lst), end(lst));
			for(long long prime1 = 0; prime1 < lst.size(); prime1 ++)
				for(long long prime2 = prime1 + 1; prime2 < lst.size(); prime2 ++)
					for(long long prime3 = prime2 + 1; prime3 < lst.size(); prime3 ++)
						if(lst[prime3] - lst[prime2] == lst[prime2] - lst[prime1])
							cout << lst[prime1] << lst[prime2] << lst[prime3] << '\n';
			END:;
			for(long long val: lst)	mp[val] = true;
		}
	return EXIT_SUCCESS;
}
//	Title:	Problem 49 - Prime permutations
//	URL:	https://projecteuler.net/problem=49
//	Input:	4
//	Output:	148748178147
//		296962999629
//	Lang:	C++