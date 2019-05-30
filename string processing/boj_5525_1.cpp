#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> getPi(string pattern) {
	int j = 0;
	int len = pattern.length();
	vector<int>pi(len, 0);
	for (int i = 1; i < len; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j-1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
int kmp(string str, string pattern) {
	vector<int>pi = getPi(pattern);
	int j = 0,ans=0;
	for (int i = 0; i < str.length(); i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (str[i] == pattern[j]) {
			if (j == pattern.length() - 1) {
				ans++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, pattern;
	pattern = "IOI";
	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		pattern += "OI";
	}
	cin >> str;
	cout << kmp(str, pattern) << '\n';
	return 0;
}