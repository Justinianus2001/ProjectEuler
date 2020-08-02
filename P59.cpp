#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

inline string tokenize(string text, char delim){
	string tokens;
	int start = text.find_first_not_of(delim), end = 0;
	while((end = text.find_first_of(delim, start)) != string::npos)
		tokens += (char)stoi(text.substr(start, end - start)),
		start = text.find_first_not_of(delim, end);
	if(start != string::npos) tokens += (char)stoi(text.substr(start));
	return tokens;
}

int main(){
	freopen("P59.txt", "r", stdin);
	string inp, encrypted, form = ";:,.+[]/\'\"?-!()";
	cin >> inp;
	encrypted = tokenize(inp, ',');
	for(char key1 = 'a'; key1 <= 'z'; key1 ++)
		for(char key2 = 'a'; key2 <= 'z'; key2 ++)
			for(char key3 = 'a'; key3 <= 'z'; key3 ++){
				string key = {key1, key2, key3}, decrypt = encrypted;
				for(int idx = 0; idx < decrypt.length(); idx ++){
					decrypt[idx] ^= key[idx % 3];
					if(!isalnum(decrypt[idx])
					&& !isspace(decrypt[idx])
					&& form.find(decrypt[idx]) == string::npos)		goto NEXT;
				}
				cout << accumulate(begin(decrypt), end(decrypt), 0);
				NEXT:;
			}
	return 0;
}
//	Title:	Problem 59 - XOR decryption
//	URL:	https://projecteuler.net/problem=59
//	Time:	O(n*17576)
//	Input:	P59.txt
//	Output:	129448
//	Lang:	C++
