#include<iostream>
using namespace std;
#define MAX 1001
#define max(a,b)(a>b?a:b)
int dx[3] = { 0,1,1 };	//	1번 아래 2번 오른쪽 3번 대각선
int dy[3] = { 1,0,1 };	//
int board[MAX][MAX];
int n, m;
int dp[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	dp[0][0] = board[0][0];
	for (int i = 1; i < m; i++) {
		dp[0][i] = dp[0][i - 1] + board[0][i];
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + board[i][0];
	}
	for (int y = 1; y < n; y++) {
		for (int x = 1; x < m; x++) {
			dp[y][x] = max(board[y][x] + dp[y - 1][x], max(board[y][x] + dp[y][x - 1], board[y][x] + dp[y - 1][x - 1]));
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
	return 0;
}