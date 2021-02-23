#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int answer = 0;
void getPi(string pattern) {
	vector<int> pi( pattern.length(),0);
	int j = 0;
	for (int i = 1; i < pattern.length(); i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
			answer = max(pi[i], answer);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
		getPi(str.substr(i, str.length()));
	cout << answer << '\n';
	return 0;
}