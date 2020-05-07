#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 102
int N, M, R;
int board[MAX][MAX];
int tmp_board[MAX][MAX];
int n_len, m_len;
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << ' ';
		}cout << '\n';
	}
}
void oneCmd() {
	int half = (N / 2);
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < M; j++) {
			int tmp = board[i][j];
			board[i][j] = board[(N-1) - i][j];
			board[(N - 1) - i][j] = tmp;
		}
	}
}
void twoCmd() {
	int half = (M / 2);
	for (int j = 0; j < half; j++) {
		for (int i = 0; i < N; i++) {
			int tmp = board[i][j];
			board[i][j] = board[i][(M - 1) - j];
			board[i][(M - 1) - j] = tmp;
		}
	}
}
void threeCmd() {
	memset(tmp_board, 0, sizeof(tmp_board));
	int h = N;
	swap(N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp_board[i][j] = board[h-1-j][i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = tmp_board[i][j];
		}
	}
}
void fourCmd() {
	
	memset(tmp_board, 0, sizeof(tmp_board));
	int w = M;
	swap(N, M);
	for (int i = 0; i < N; i++) {
		for (int j= 0; j < M; j++) {
			tmp_board[i][j] = board[j][w-1-i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = tmp_board[i][j];
		}
	}
}
void fiveCmd() {
	memset(tmp_board, 0, sizeof(tmp_board));
	int half_n = (N / 2);
	int half_m = (M / 2);
	//1 -> 2
	for (int i = 0; i < half_n; i++) {
		for (int j = 0; j < half_m; j++) {
			tmp_board[i][j + half_m] = board[i][j];
		}
	}
	//2 ->3
	for (int i = 0; i < half_n; i++) {
		for (int j = half_m; j < M; j++) {
			tmp_board[i+half_n][j] = board[i][j];
		}
	}
	//3->4
	for (int i = half_n; i < N; i++) {
		for (int j = half_m; j < M; j++) {
			tmp_board[i][j - half_m] = board[i][j];
		}
	}
	//4->1
	for (int i = half_n; i < N; i++) {
		for (int j = 0; j < half_m; j++) {
			tmp_board[i-half_n][j] = board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = tmp_board[i][j];
		}
	}
}
void sixCmd() {
	memset(tmp_board, 0, sizeof(tmp_board));
	int half_n = (N / 2);
	int half_m = (M / 2);
	//1 <- 2
	for (int i = 0; i < half_n; i++) {
		for (int j = half_m; j < M; j++) {
			tmp_board[i][j - half_m] = board[i][j];
		}
	}
	//2 <- 3
	for (int i = half_n; i < N ; i++) {
		for (int j = half_m; j < M; j++) {
			tmp_board[i - half_n][j] = board[i][j];
		}
	}
	//3 <- 4
	for (int i = half_n; i < N; i++) {
		for (int j = 0; j < half_m; j++) {
			tmp_board[i][j + half_m] = board[i][j];
		}
	}
	//4 <- 1
	for (int i = 0; i < half_n; i++) {
		for (int j = 0; j < half_m; j++) {
			tmp_board[i+half_n][j] = board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = tmp_board[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			oneCmd();
		}
		else if (num == 2) {
			twoCmd();
		}
		else if (num == 3) {
			threeCmd();
		}
		else if (num == 4) {
			fourCmd();
		}
		else if (num == 5) {
			fiveCmd();
		}
		else {
			sixCmd();
		}
	}

	print();

	return 0;
}