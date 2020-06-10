#include<iostream>
#include<vector>
using namespace std;
#define MAX 2002
bool dp[MAX][MAX];
int arr[MAX];
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) dp[i][i] = true;
	for (int i = 1; i < N; i++)
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = dp[i + 1][i] = true;
	
	for (int i = 2; i < N; i++) {	//이게 길이
		for (int j = 1; j <= N; j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = dp[j + i][j] = true;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e,answer = 0;
		cin >> s >> e;
		if (dp[s][e]) answer = 1;
		cout << answer << '\n';
	}

	return 0;
}