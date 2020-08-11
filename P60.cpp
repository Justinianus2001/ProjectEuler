#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes, edge[10000];
bool visited[10000];
int inp, ans = INT_MAX;

inline void sieve(int range){
	for(int num = 3; num <= range; num += 2){
		bool isPrime = true;
		for(int prime: primes)
			if(!(num % prime)){	isPrime = false;	break;	}
		if(isPrime)		primes.push_back(num);
	}
}

inline int pow(int base, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1)		ans *= base;
		exp /= 2, base *= base;
	}
	return ans;
}

inline int log10(int num){
	int ans = 0;
	do num /= 10, ans ++;
	while(num);
	return ans;
}

inline long long mergeNum(long long lhs, long long rhs){
	return lhs * pow(10, log10(rhs)) + rhs;
}

inline long long mul(long long lhs, long long rhs, long long MOD){
	return (lhs % MOD) * (rhs % MOD) % MOD;
}


inline long long pow(long long base, long long exp, long long MOD){
	long long res = 1;
	while(exp){
		if(exp & 1)	res = mul(res, base, MOD);
		exp /= 2, base = mul(base, base, MOD);
	}
	return res;
}

//	Miller-Rabin-test
inline bool isPrime(long long p){
	int bitmaskPrimes2to31 = (1 <<  2) | (1 <<  3) | (1 <<  5) | (1 <<  7)
				| (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19)
				| (1 << 23) | (1 << 29);
	if(p < 31)	return bitmaskPrimes2to31 & (1 << p);
	if(!(p % 2) || !(p % 3) || !(p % 5) || !(p % 7)
	|| !(p % 11) || !(p % 13) || !(p % 17))		return false;
	if(p < 17 * 19)		return true;
	int STOP = 0;
	int TestAgainst1[] = {377687, STOP};
	int TestAgainst2[] = {31, 73, STOP};
	int TestAgainst3[] = {2, 7, 61, STOP};
	int TestAgainst4[] = {2, 13, 23, 1662803, STOP};
	int TestAgainst7[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022, STOP};
	int* testAgainst = TestAgainst7;
	if(p < 5329)			testAgainst = TestAgainst1;
	else if(p < 9080191)		testAgainst = TestAgainst2;
	else if(p < 4759123141ULL)	testAgainst = TestAgainst3;
	else if(p < 1122004669633ULL)	testAgainst = TestAgainst4;
	long long d = (p - 1) >> 1;
	int shift = 0;
	while((d & 1) == 0)		shift ++, d >>= 1;
	do{
    		long long x = pow(*testAgainst ++, d, p);
    		if(x == 1 || x == p - 1)	continue;
		bool maybePrime = false;
		for(int r = 0; r < shift; r ++){
			x = pow(x, 2, p);
			if(x == 1)		return false;
			if(x == p - 1){
        		maybePrime = true;
				break;
			}
    		}
		if(!maybePrime)		return false;
	}while(*testAgainst != STOP);
	return true;
}

inline void dfs(vector<int> path, int cur, int cnt, int sum){
	sum += cur;
	if(cnt == inp){
		bool match = true;
		for(int idx1 = 0; idx1 < path.size(); idx1 ++)
			for(int idx2 = idx1 + 1; idx2 < path.size(); idx2 ++)
				if(!binary_search(begin(edge[path[idx1]]), end(edge[path[idx1]]), path[idx2])){
					match = false;		break;
				}
		if(match)	ans = min(ans, sum);
	}
	else
		for(int next: edge[cur]){
			if(next <= cur)		continue;
			if(!visited[next])
				visited[next] = true,
				path.push_back(next),
				dfs(path, next, cnt + 1, sum),
				path.pop_back(),
				visited[next] = false;
		}
}

int main(){
	sieve(10000);
	for(int idx1 = 0; idx1 < primes.size(); idx1 ++)
		for(int idx2 = idx1 + 1; idx2 < primes.size(); idx2 ++)
			if(isPrime(mergeNum(primes[idx1], primes[idx2]))
			&& isPrime(mergeNum(primes[idx2], primes[idx1])))
			edge[primes[idx1]].push_back(primes[idx2]),
			edge[primes[idx2]].push_back(primes[idx1]);
	cin >> inp;
	for(int prime: primes)
		visited[prime] = true,
		dfs({prime}, prime, 1, 0),
		visited[prime] = false;
	cout << ans;
	return 0;
}
//	Title:	Problem 60 - Prime pair sets
//	URL:	https://projecteuler.net/problem=60
//	Time:	O(?)
//	Input:	5
//	Output:	26033
//	Lang:	C++
