#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
#include<string.h>
using namespace std;
#define MAX 101
typedef pair<int, int>pii;
typedef pair<int, pair<int, pair<int, int>>> piiii;	// 명령횟수, 방향 ,x,y
int board[MAX][MAX];			
bool visited[MAX][MAX][5];		//x,y 방향
int n,m,startX, startY, startDir, destX, destY, destDir;
enum {
	east=1, west, south, north
};
bool rangeCheck(int x, int y) {
	return (x > 0 && x <= m&&y > 0 && y <= n) ? true : false;
}
int bfs() {
	priority_queue<piiii, vector<piiii>, greater<piiii>>pq;
	pq.push(make_pair(0, make_pair(startDir, make_pair(startX, startY))));
	while (!pq.empty()) {
		int currentCmd = pq.top().first;
		int currentDir = pq.top().second.first;
		int currentX = pq.top().second.second.first;
		int currentY = pq.top().second.second.second;
		if (currentX == destX && currentY == destY && currentDir == destDir) {
			return currentCmd;
		}
		pq.pop();
		if (!visited[currentY][currentX][currentDir]) {
			visited[currentY][currentX][currentDir] = true;
			int nextCmd = currentCmd + 1;
			int nextDir = currentDir;
			int nextX = currentX;
			int nextY = currentY;

			//방향 변경 
			switch (currentDir) {
			case east:
				nextDir = south;
				if(!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				nextDir = north;
				if (!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				break;
			case west:
				nextDir = south;
				if (!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				nextDir = north;
				if (!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				break;
			case south:
				nextDir = east;
				if (!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				nextDir = west;
				if (!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				break;
			case north:
				 nextDir = east;
				if (!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				nextDir = west;
				if (!visited[currentY][currentX][nextDir])
					pq.push(make_pair(nextCmd, make_pair(nextDir, make_pair(currentX, currentY))));
				break;
			}
			//방향 변경 안하고 이동
			switch (currentDir) {
			case east:
				nextY = currentY;
				for (int i = 1; i <= 3; i++) {
					nextX = currentX + i;
					if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 0 && !visited[nextY][nextX][east]) {
						pq.push(make_pair(nextCmd, make_pair(east, make_pair(nextX, nextY))));
					}
					else if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 1 && !visited[nextY][nextX][east]) {
						break;
					}
				}
				break;
			case west:
				nextY = currentY;
				for (int i = 1; i <= 3; i++) {
					nextX = currentX - i;
					if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 0 && !visited[nextY][nextX][west]) {
						pq.push(make_pair(nextCmd, make_pair(west, make_pair(nextX, nextY))));
					}
					else if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 1 && !visited[nextY][nextX][west]) {
						break;
					}
				}
				break;
			case south:
				nextX = currentX;
				for (int i = 1; i <= 3; i++) {
					nextY = currentY + i;
					if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 0 && !visited[nextY][nextX][south]) {
						pq.push(make_pair(nextCmd, make_pair(south, make_pair(nextX, nextY))));
					}
					else if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 1 && !visited[nextY][nextX][south]) {
						break;
					}
				}
				break;
			case north:
				nextX = currentX;
				for (int i = 1; i <= 3; i++) {
					nextY = currentY - i;
					if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 0 && !visited[nextY][nextX][north]) {
						pq.push(make_pair(nextCmd, make_pair(north, make_pair(nextX, nextY))));
					}
					else if (rangeCheck(nextX, nextY) && board[nextY][nextX] == 1 && !visited[nextY][nextX][north]) {
						break;
					}
				}
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	cin >> startY >> startX >> startDir >> destY >> destX >> destDir;

	int ans=bfs();
	cout << ans << '\n';
	return 0;
}