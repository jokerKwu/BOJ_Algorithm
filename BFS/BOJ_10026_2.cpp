#include<iostream>
#include<queue>
#include<vector>

using namespace std;
#define MAX 102

int N;
int m_xy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
char board[MAX][MAX][2]; //0 정상 1 비정상
bool visited[MAX][MAX][2];
int answer[2];
typedef struct {
	int x;
	int y;
}Point;

void bfs(int x,int y,int index) {
	queue<Point> q;
	char ch = board[y][x][index];
	q.push({ x,y });
	while (!q.empty()) {
		Point cur_pos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			
			Point next_pos = { cur_pos.x + m_xy[i][0],cur_pos.y + m_xy[i][1] };
			
			if (next_pos.x < 0 || next_pos.y < 0 || next_pos.x >= N || next_pos.y >= N) continue;
			
			if (!visited[next_pos.y][next_pos.x][index] && board[next_pos.y][next_pos.x][index] == ch) {
				q.push(next_pos);
				visited[next_pos.y][next_pos.x][index] = true;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j][0];
			if (board[i][j][0] == 'R') {
				board[i][j][1] = 'G';
			}
			else {
				board[i][j][1] = board[i][j][0];
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				if (!visited[i][j][k]) {
					bfs(j,i,k);
					answer[k]++;
				}
			}
		}
	}
	
	for (int i = 0; i < 2; i++) cout << answer[i] << ' ';
	
	return 0;
}