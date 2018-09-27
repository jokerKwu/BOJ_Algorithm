#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
long long dp[68];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 67; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	while (testCase--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}