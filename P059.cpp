/*
 * Copyright (c) Justinianus
 * https://github.com/Justinianus2001/ProjectEuler
 */
#include "library.hpp"

int main(int argc, char** argv){
	freopen("P059.txt", "r", stdin);
	string str, encrypted, form = ";:,.+[]/\'\"?-!()";
	cin >> str;
	vector<string> token = tokenize(str, ",");
	for(string ch: token)
		encrypted += stoll(ch);
	for(char key1 = 'a'; key1 <= 'z'; key1 ++)
		for(char key2 = 'a'; key2 <= 'z'; key2 ++)
			for(char key3 = 'a'; key3 <= 'z'; key3 ++){
				string key = {key1, key2, key3}, decrypt = encrypted;
				for(long long idx = 0; idx < decrypt.length(); idx ++){
					decrypt[idx] ^= key[idx % 3];
					if(!isalnum(decrypt[idx]) && !isspace(decrypt[idx])
					&& form.find(decrypt[idx]) == string::npos)		goto NEXT;
				}
				cout << accumulate(begin(decrypt), end(decrypt), 0);
				NEXT:;
			}
	return EXIT_SUCCESS;
}
//	Title:	Problem 59 - XOR decryption
//	URL:	https://projecteuler.net/problem=59
//	Input:	P059.txt
//	Output:	129448
//	Lang:	C++