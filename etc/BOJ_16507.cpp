#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1001
int board[MAX][MAX];
int dp[MAX][MAX];
typedef pair<int, pair<int, pair<int, int>>> piiii;	//startY , startX, destY, destX 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c, q;
	cin >> r >> c >> q;
	vector<piiii>v;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			dp[i][j] = board[i][j]+dp[i][j - 1];
		}
	}

	for (int i = 0; i < q; i++) {
		int startX, startY, destX, destY;
		cin >> startY >> startX >> destY >> destX;
		int ans = 0, total = 0, cnt = 0;
		for (int i = startY; i <= destY; i++) {
			total =total+ (dp[i][destX] - dp[i][startX - 1]);
		}
		cnt = ((destY - startY) + 1) * ((destX - startX) + 1);
		ans = total / cnt;
		cout << ans << '\n';
	}


	return 0;
}
