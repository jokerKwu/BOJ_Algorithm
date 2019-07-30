#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int alpha[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		memset(alpha, 0, sizeof(alpha));
		string str;
		cin >> str;
		bool OK = true;
		for (int j = 0; j < str.length(); j++) {
			alpha[str[j] - 'A']++;
			if (alpha[str[j] - 'A'] == 3) {
				if (j + 1 < str.length() && str[j] == str[j + 1]) {
					j++;
					alpha[str[j] - 'A'] = 0;
				}
				else {
					OK = false;
					break;
				}
			}
		}
		for (int j = 0; j < 26; j++) {
			if (alpha[j] == 3) {
				OK = false;
				break;
			}
		}
		if (OK) cout << "OK\n";
		else cout << "FAKE\n";
	}

	return 0;
}