#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 101
bool dp[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		memset(dp, false, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				if (dp[j] == true) {
					dp[j] = false;
				}
				else {
					dp[j] = true;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dp[i])
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}