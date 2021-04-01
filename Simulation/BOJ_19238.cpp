#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<stdlib.h>
using namespace std;
#define MAX 23
int N, M, K;
int board[MAX][MAX];
int startBoard[MAX][MAX];
int endBoard[MAX][MAX];
int visit[MAX][MAX];
vector<pair<int, int>> startArr, endArr;
typedef pair<int, int> pii;	//y ,x
pii taxiPos;	//y x
int m_xy[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visit[i][j] << ' ';
		}cout << '\n';
	}
}
void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = -1;
		}
	}
}
void bfs() {
	int answer = -1;
	queue<pii> q;
	init();
	q.push(taxiPos);
	visit[taxiPos.first][taxiPos.second] = 0;
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		int cur_cnt = visit[cur_y][cur_x];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + m_xy[i][0];
			int next_x = cur_x + m_xy[i][1];
			int next_cnt = cur_cnt + 1;
			//¹üÀ§ ¹þ¾î³µ´ÂÁö Ã¼Å©
			if (next_y< 1 || next_x < 1 || next_x >N || next_y >N) continue;

			if (visit[next_y][next_x] == -1 && board[next_y][next_x] == 0) {
				visit[next_y][next_x] = next_cnt;
				q.push({ next_y,next_x });
			}
		}
	}
}
int findCustomer()
{
	int answer = -1;
	int x, y;
	int min_dist = 987654321;
	for (int i = 0; i < startArr.size(); i++) {
		int cy = startArr[i].first;
		int cx = startArr[i].second;
		if (startBoard[cy][cx] > 0&& visit[cy][cx] >=0 ) {
			if (min_dist > visit[cy][cx]) {
				min_dist = visit[cy][cx];
				x = cx;
				y = cy;
				answer = i;
			}
			else if (min_dist == visit[cy][cx]) {
				if (y > cy) {
					answer = i;
					x = cx;
					y = cy;
				}
				else if (y == cy) {
					if (x > cx) {
						answer = i;
						x = cx;
						y = cy;
					}
				}
			}
		}
	}

	if (min_dist <= K) {
		K -= min_dist;
		return answer;
	}
	else return -1;
}
int endCustomer(int index) {
	int dist = visit[endArr[index].first][endArr[index].second];
	if (dist <= K) return dist;
	else return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	cin >> taxiPos.first >> taxiPos.second;
	for (int i = 1; i <= M; i++) {
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;
		startArr.push_back({ sy,sx });
		endArr.push_back({ ey,ex });
		startBoard[sy][sx] = i;
		endBoard[ey][ex] = i;
	}
	for (int i = 0; i < M; i++) {
		bfs();
		int minIndex = findCustomer();
		if (minIndex == -1) {
			cout << -1 << '\n';
			return 0;
		}
		taxiPos = startArr[minIndex];
		startBoard[taxiPos.first][taxiPos.second] = 0;
		bfs();
		int d = endCustomer(minIndex);
		if (d == -1) {
			cout << -1 << '\n';
			return 0;
		}
		taxiPos = endArr[minIndex];
		K += d;
	}
	cout << K << '\n';
	return 0;
}