#include<iostream>
using namespace std;
#define MAX 100001
int dp[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		dp[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1)
				dp[i] = dp[i - j * j] + 1;
		}
	}
	cout << dp[num] << '\n';
	return 0;
}