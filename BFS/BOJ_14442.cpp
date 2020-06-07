#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#include<stdlib.h>

using namespace std;
#define MAX 1002
int N, M, K;
char board[MAX][MAX];
int visited[11][MAX][MAX];
int m_xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
typedef struct {
	int c;
	int x;
	int y;
}Info;


int bfs() {
	queue<Info> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		Info c_info = q.front();
		
		//목적지에 도달했으므로 
		if (c_info.x == M - 1 && c_info.y == N-1) {
			return visited[c_info.c][c_info.y][c_info.x];
		}

		q.pop();
		for (int i = 0; i < 4; i++) {
			Info n_info = { c_info.c,c_info.x + m_xy[i][0],c_info.y + m_xy[i][1] };
			int n_move_cnt = visited[c_info.c][c_info.y][c_info.x] + 1;

			if (n_info.x < 0 || n_info.y < 0 || n_info.x >= M || n_info.y >= N) continue;
			
			//다음 좌표가 벽이 아닌 경우 방문을 안했거나 , 이동횟수가 더 작다면
			if (board[n_info.y][n_info.x] == '0' && (visited[n_info.c][n_info.y][n_info.x]==0||visited[n_info.c][n_info.y][n_info.x]>n_move_cnt)) {
				visited[n_info.c][n_info.y][n_info.x] = n_move_cnt;
				q.push(n_info);
			}
			//다음 좌표가 벽인 경우 현재까지 부순 벽의 개수가 K 보다 작다면 부술수 있으니
			else if (board[n_info.y][n_info.x] == '1'&& K > c_info.c) {
				n_info.c = c_info.c + 1;//벽을 부수고 이동
				if (visited[n_info.c][n_info.y][n_info.x] == 0 || visited[n_info.c][n_info.y][n_info.x] > n_move_cnt) {
					visited[n_info.c][n_info.y][n_info.x] = n_move_cnt;
					q.push(n_info);
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	cout<<bfs()<<'\n';

	return 0;
}
