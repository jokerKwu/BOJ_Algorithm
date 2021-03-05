#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 102
int N, M;
char board[MAX][MAX];
char answer[MAX][MAX];
int m_xy[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };
vector<pair<int, int>> arr;		// x ,y 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		//init
		arr.clear();
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				answer[i][j] = '0';
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					arr.push_back({ j,i });
					answer[i][j] = '*';
				}
			}
		}
		
		for (int i = 0;i < arr.size();i++) {
			int x = arr[i].first;
			int y = arr[i].second;
			for (int j = 0;j < 8;j++) {
				int nx = x + m_xy[j][0];
				int ny = y + m_xy[j][1];
				if (0 <= nx && nx < M && 0 <= ny && ny < N) {
					if (board[ny][nx] == '.') {
						int tmp = answer[ny][nx] - '0';
						answer[ny][nx] = (tmp + 1) + '0';
					}
				}
			}
		}
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				cout << answer[i][j];
			}cout << '\n';
		}
	}
	return 0;
}