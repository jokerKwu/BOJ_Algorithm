#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 101
int board[MAX][MAX];
int answer[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int n = 1;n <= N;n++) {
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		for (int i = y;i < y + h;i++) {
			for (int j = x;j < x + w;j++) {
				board[i][j] = n;
			}
		}

	}
	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			if (board[i][j] != 0) {
				answer[board[i][j]]++;
			}
		}
	}
	for (int i = 1;i <= N;i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}