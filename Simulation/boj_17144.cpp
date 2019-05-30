#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define MAX 51

int R, C, T;
int board[MAX][MAX],tmp_board[MAX][MAX];
int m_xy[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };	// 0위 1오른쪽 2 아래 3 왼쪽

bool visited[MAX][MAX];

void print() {
	cout << "=========== Map =================\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j]<<' ';
		}cout << '\n';
	}
	cout << "====================================\n";
}
void move_function(int x,int y,int dir) {
	if (dir == -1) {//반시계방향
				// 1. 공기청정기 위에서부터 (0, 0)까지 모든 값 떙겨주기
				for (int i = y-1; i > 0; i--)
				{
					board[i][0] = board[i - 1][0];
				}
				// 2. 가장 윗줄 땡겨주기
				for (int i = 0; i < C - 1; i++)
				{
					board[0][i] = board[0][i + 1];
				}
				// 3. 반대편 세로라인 땡겨주기
				for (int i = 1; i <= y; i++)
				{
					board[i - 1][C - 1] = board[i][C - 1];
				}
				// 4. 공기청정기 라인 땡겨주기
				for (int i = C - 1; i > 1; i--)
				{
					board[y][i] = board[y][i - 1];
				}
				board[y][1] = 0;
	}
	else {
		for (int i = y + 1; i < R - 1; i++)
		{
			board[i][0] = board[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++)
		{
			board[R - 1][i] = board[R - 1][i + 1];
		}
		for (int i = R - 1; i >= y; i--)
		{
			board[i][C - 1] = board[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--)
		{
			board[y][i] = board[y][i - 1];
		}
		board[y][1] = 0;
	}
}
bool range_check(int x,int y) {
	if (x >= 0 && y >= 0 && x < C&&y < R&&board[y][x]!=-1) return true;
	else return false;
}

void dust_bfs() {

	for (int time = 0; time < T; time++) {
		
		//미세먼지 확산
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				tmp_board[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] != 0 && board[i][j] != -1) {
					int cnt = 0;
					int value = board[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int n_x = j + m_xy[k][0];
						int n_y = i + m_xy[k][1];
						if (range_check(n_x, n_y)) {
							tmp_board[n_y][n_x] = tmp_board[n_y][n_x] + value;
							cnt++;
						}
					}
					tmp_board[i][j] = tmp_board[i][j] - (cnt*value);
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				board[i][j] = tmp_board[i][j];
			}
		}

		//공기청정기 작동
		bool dir = false;
		for (int i = 0; i < R; i++) {
			if (board[i][0] == -1) {
				if (!dir) {
					move_function(0, i, -1);
					dir = true;
				}
				else {
					move_function(0, i, 1);
					dir = false;
				}
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> R >> C >> T;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	//미세먼지 확산 + 공기청정기
	dust_bfs();

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] > 0) {
				ans += board[i][j];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}