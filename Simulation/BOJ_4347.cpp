#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
char board[3][3];
int x_cnt, o_cnt;
bool visit[3][3];
int m_xy[8][2] = { {0,1},{1,0},{1,1},{-1,-1},{1,-1},{-1,1},{0,-1},{-1,0} };

int check() {
	int o_cnt = 0;
	int x_cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			if (board[i][0] == 'X') x_cnt++;
			else o_cnt++;
		}
	}
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
			if (board[0][j] == 'X') x_cnt++;
			else o_cnt++;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[0][0] == 'X') x_cnt++;
		else o_cnt++;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[0][2] == 'X') x_cnt++;
		else o_cnt++;
	}
	if (x_cnt != 0 && o_cnt != 0) return -1;
	if (o_cnt != 0) return 0;
	else if (x_cnt != 0) return 1;
	else return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		x_cnt = 0;
		o_cnt = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'O') {
					o_cnt++;
				}
				else if (board[i][j] == 'X') {
					x_cnt++;
				}
			}
		}
		if (x_cnt == o_cnt || x_cnt == o_cnt+1) {
			if (x_cnt == o_cnt + 1) {
				//x가 이기거나 비긴경우
				if (check() == 1 || check() == 2) cout << "yes\n";
				else cout << "no\n";
			}
			else {
				//o가 이기거나 비긴경우
				if (check() == 0 || check() == 2) cout << "yes\n";
				else cout << "no\n";
			}
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}