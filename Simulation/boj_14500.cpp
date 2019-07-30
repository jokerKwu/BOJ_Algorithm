#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 501

int board[MAX][MAX];
bool visited[MAX][MAX];
int N, M,answer=0;
int m_xy[3][2] = { {0,1},{1,0},{-1,0} };

int t_xy[4][3][2] = {
	{{-1,-1},{0,-1},{1,-1}},
	{{-1,-1},{-1,0},{-1,1}},
	{{1,-1},{1,0},{1,1}},
	{{-1,1},{0,1},{1,1}}
};


void dfs(int x, int y, int cnt,int total) {
	if (cnt == 4) {
		answer = max(answer, total);
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + m_xy[i][0];
		int ny = y + m_xy[i][1];
		
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

		if (!visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(nx, ny, cnt + 1, total + board[ny][nx]);
			visited[ny][nx] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(j, i, 1,board[i][j]);
				visited[i][j] = false;
			}
			for (int k = 0; k < 4; k++) {
				int total = board[i][j];
				int ax[3], ay[3];
				bool OK = true;
				for (int kk = 0; kk < 3; kk++) {
					ax[kk] = j + t_xy[k][kk][0];
					ay[kk] = i + t_xy[k][kk][1];
					if (ax[kk] < 0 || ay[kk] < 0 || ax[kk] >= M || ay[kk] >= N) {
						OK = false;
						break;
					}
				}
				if (OK) {
					for (int z = 0; z < 3; z++) {
						total += board[ay[z]][ax[z]];
					}
					answer = max(answer, total);
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}