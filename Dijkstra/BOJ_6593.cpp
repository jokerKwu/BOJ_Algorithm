#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define MAX 31
char board[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
//거리 층, y축 x축
/*
BFS는 큐에서 뺀 다음에 방문 체크를 하는 것이 아니라 큐에 넣을 때 해야 합니다. 여러 정점에서 한 정점을 동시에 방문하려고 할 수 있기 때문입니다.
*/
typedef pair<int, pair<int, pair<int, int>>> piiii;
int dx[6] = { 0,0,1,0,-1,0 };
int dy[6] = { 0,0,0,1,0,-1 };
int dz[6] = { 1,-1,0,0,0,0 };
int bfs(int sl,int sr,int sc,int l, int r, int c) {
	queue<piiii>pq;//거리랑 이동좌표
	visited[sl][sr][sc] = true;
	pq.push(make_pair(0, make_pair(sl,make_pair(sr,sc))));
	while (!pq.empty()) {
		int curD = pq.front().first;
		int curL = pq.front().second.first;
		int curR = pq.front().second.second.first;
		int curC = pq.front().second.second.second;
		pq.pop();
		if (board[curL][curR][curC] == 'E') {
			return curD;
		}
		for (int i = 0; i < 6; i++) {
			int nextL = curL + dz[i];
			int nextR = curR + dy[i];
			int nextC = curC + dx[i];
			int nextD = curD + 1;
			if (board[nextL][nextR][nextC] == '.'||board[nextL][nextR][nextC]=='E') {
				if (nextL > 0 && nextR > 0 && nextC > 0 && nextL <= l && nextR <= r && nextC <= c && !visited[nextL][nextR][nextC]) {
					visited[nextL][nextR][nextC] = true;
					pq.push(make_pair(nextD, make_pair(nextL, make_pair(nextR, nextC))));
				}
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r, c;
	cin >> l >> r >> c;
	while (l != 0 && r != 0 && c != 0) {
		memset(board, '\0', sizeof(board));
		memset(visited, false, sizeof(visited));
		int startL, startR, startC;
		for (int k = 1; k <= l; k++) {
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					cin >> board[k][i][j];
					if (board[k][i][j] == 'S') {
						startL = k; startR = i; startC = j;
					}
				}
			}
		}
		int res = 0;
		res=bfs(startL, startR, startC,l,r,c);
		if (res != 0) {
			printf("Escaped in %d minute(s).\n", res);
		}
		else {
			printf("Trapped!\n");
		}
		
		cin >> l >> r >> c;
	}
	return 0;
}
