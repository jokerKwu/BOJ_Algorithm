#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX 101
#define F 10
#define P 11
#define S 12
int board_col[MAX][MAX], board_row[MAX][MAX];
int N, L,ans;
void checkFunction(int board[MAX][MAX]) {
	for (int i = 0; i < N; i++) { 
		int cnt = 1; // 높이가 같은 타일 수
		for (int j = 1; j < N; j++) {
			int prev = board[i][j - 1];
			int cur = board[i][j];
			// 높이가 같으면
			if (prev == cur)
				cnt++;
			// 내리막이면
			else if (prev - cur == 1 && cnt >= 0)
				cnt = -L + 1;
			// 오르막이면
			else if (prev - cur == -1 && cnt >= L)
				cnt = 1;
			else {
				cnt = -1;
				break;
			}
		}
		if (cnt >= 0)
			ans++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board_col[i][j];
			board_row[j][i] = board_col[i][j];
		}
	}
	checkFunction(board_col);
	checkFunction(board_row);

	cout << ans << '\n';

	return 0;
}