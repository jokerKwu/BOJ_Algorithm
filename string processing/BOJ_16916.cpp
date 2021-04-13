#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
vector<int> getPi(string pattern) {
	vector<int> pi(pattern.length(),0);
	int j = 0;
	for (int i = 1;i < pattern.length();i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

bool kmp(string str, string pattern) {
	int j = 0;
	vector<int> pi = getPi(pattern);
	for (int i = 0;i < str.length();i++) {
		while (j > 0 && pattern[j] != str[i]) {
			j = pi[j - 1];
		}
		if (pattern[j] == str[i]) {
			if (pattern.length() - 1 == j) {
				return true;
			}
			else {
				j++;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str, pattern;
	getline(cin, str);
	getline(cin, pattern);

	cout << kmp(str, pattern) << '\n';

	return 0;
}