#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 105
vector<pair<int, int>>warmholes[11];		//x,y
int board[MAX][MAX],n,ans;
//상 하 좌 우
int dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
//블록 , 방향
int dirChange[6][4] = { {0,0,0,0},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1} };

void dfs(int x, int y) {
	for (int d = 0; d < 4; d++) {
		int point = 0;
		queue < pair<int, pair<int, int>>>q;
		q.push(make_pair(d, make_pair(x, y)));	//방향 x , y
		while (!q.empty()) {
			
			int curD = q.front().first;
			int curX = q.front().second.first;
			int curY = q.front().second.second;
			q.pop();
			//cout << curX << ' ' << curY << '\n';
			int nextX = curX + dir[curD][0];
			int nextY = curY + dir[curD][1];
			int nextD = curD;
			//블랙홀을 만나면 종료
			if (board[nextY][nextX] == -1 || (nextX == x && nextY == y)) break;

			//1~5번 블록을 만난 경우
			if (board[nextY][nextX] >= 1 && board[nextY][nextX] <= 5) {
				nextD = dirChange[board[nextY][nextX]][curD];
				point++;
			}
			
			//웜홀을 만나게 된 경우
			if (board[nextY][nextX] >= 6 && board[nextY][nextX] <= 10) {
				for (int i = 0; i < warmholes[board[nextY][nextX]].size(); i++) {
					int tmpX = warmholes[board[nextY][nextX]][i].first;
					int tmpY = warmholes[board[nextY][nextX]][i].second;
					if (nextY != tmpY || nextX != tmpX) {
						nextX = tmpX; nextY = tmpY;
						break;
					}
				}
			}
			if (nextX >= 0 && nextX <= n+1 && nextY >= 0 && nextY <= n+1) {
				q.push(make_pair(nextD, make_pair(nextX, nextY)));
			}
		}
		ans = max(ans, point);
	}
}
void init() {
	ans = 0;
	memset(board, 0, sizeof(board));
	for (int i = 0; i <= 10; i++)
		warmholes[i].clear();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		cin >> n;
		for (int i = 0; i < n+2; i++) {
			for (int j = 0; j < n+2; j++) {
				if (i == 0 || j == 0 || i == n+1 || j == n+1) board[i][j] = 5;
				else cin >> board[i][j];

				if (board[i][j] >= 6 && board[i][j] <= 10)
					warmholes[board[i][j]].push_back(make_pair(j, i));
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] == 0)
					dfs(j, i);//x,y
			}
		}
		cout <<'#'<<tc<<' '<<ans << '\n';
	}
	return 0;
}
