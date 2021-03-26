#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 102
#define INF 987654321
char board[MAX][MAX];
vector<int> attack;
int m_x[2] = { 1,-1 };
int m_xy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;
bool visit[MAX][MAX];
typedef struct {
	int x;
	int y;
}Point;
vector<Point> skyFallArr;
// bfs 함수를 통해서 땅에 붙어있는 블록 체크
void bfs() {
	queue<Point> q;
	//땅에 붙어있는 애들 다 체크
	for (int i = 0;i < M;i++) {
		if (board[N - 1][i] == 'x') {
			visit[N - 1][i] = true;
			q.push({ i,N - 1 }); 
		}
	}
	while (!q.empty()) {
		Point cur_pos = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			Point next_pos = { cur_pos.x + m_xy[i][0], cur_pos.y + m_xy[i][1] };
			if (next_pos.x < 0 || next_pos.y < 0 || next_pos.x >= M || next_pos.y >= N) continue;
			if (board[next_pos.y][next_pos.x] == 'x' && !visit[next_pos.y][next_pos.x]) {
				visit[next_pos.y][next_pos.x] = true;
				q.push(next_pos);
			}
		}
	}
}
//미사일을 쏴서 지우는 함수
void eraseFunc(int height, int dir) {
	int h = N - height;
	//x 좌표 이동
	if (dir == 0) {
		for (int i = 0;i < M;i++) {
			if (board[h][i] != '.') {
				board[h][i] = '.';
				return;
			}
		}
	}
	else {
		for (int i = M - 1;i >= 0;i--) {
			if (board[h][i] != '.') {
				board[h][i] = '.';
				return;
			}
		}
	}
}
//정답출력하는 함수
void print() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << board[i][j];
		}cout << '\n';
	}
}
//초기화 하는 함수
void init() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			visit[i][j] = false;
		}
	}
}
//떨어진 블록 이동시키는 함수
void moveFunc(int move) {
	for (int i = 0;i < skyFallArr.size();i++) {
		Point cur_pos = skyFallArr[i];
		Point next_pos = { skyFallArr[i].x,skyFallArr[i].y + move };
		board[cur_pos.y][cur_pos.x] = '.';
		board[next_pos.y][next_pos.x] = 'x';
	}
}
//떨어져 있는 블록 체크하는 함수
void skyBfs() {
	int result = INF;
	for (int i = N-1;i >= 0;i--) {
		for (int j = 0;j < M;j++) {
			if (visit[i][j] == 0 && board[i][j] == 'x') {
				skyFallArr.push_back({ j,i });
			}
		}
	}
	//몇칸을 움직여야 되는지 체크하자.
	for (int i = 0;i < skyFallArr.size();i++) {
		Point cur_pos = skyFallArr[i];
		int cnt = 0;
		int sx = cur_pos.x;
		int sy = cur_pos.y + 1;
		while (sy < N) {
			if (board[sy][sx] == 'x' && visit[sy][sx] == false ) {
				cnt = INF;
				break;
			}
			if (board[sy][sx] == 'x' && visit[sy][sx] == true) {
				break;
			}
			cnt += 1;
			sy += 1;
		}
		result = min(result, cnt);
	}

	if (result != INF) {
		moveFunc(result);
	}
	skyFallArr.clear();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> board[i][j];
		}
	}
	int T;
	cin >> T;
	for (int i = 0;i < T;i++) {
		int num;
		cin >> num;
		attack.push_back(num);
	}
	//미사일 발사
	for (int i = 0; i < attack.size();i++) {
		init(); //초기화
		eraseFunc(attack[i], i % 2);	//공격해서 지우자
		bfs();	//땅에 붙어 있는 애들 체크
		skyBfs();//땅에서 떨어져 있는 애들 찾기
	}
	print(); //정답 출력

	return 0;
}