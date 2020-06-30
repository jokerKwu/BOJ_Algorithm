#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define MAX 11
bool check[MAX][MAX][MAX][MAX];	//방향 좌표	 빨 , 파
char board[MAX][MAX];
int m_xy[5][2] = { {0,0}, {0,1},{0,-1},{1,0},{-1,0} };
int N, M,answer = -1;

typedef struct {
	int x;
	int y;
}Point;

Point red_ball, blue_ball;

//좌표 이동시키는 함수
Point ballCalc(Point ball, int dir) {
	Point next_ball = { ball.x + m_xy[dir][0],ball.y + m_xy[dir][1] };
	if (next_ball.y < 0 || next_ball.x < 0 || next_ball.x >= M || next_ball.y >= N) return ball;
	return next_ball;
}

//볼 계속 이동시키는 함수
Point ballMove(Point ball, int dir) {
	Point next_ball, cur_ball = ball;
	while (true) {
		next_ball = ballCalc(cur_ball, dir);
		//벽인 경우
		if (board[next_ball.y][next_ball.x] == '#') {
			next_ball = cur_ball;
			break;
		}
		//홀인 경우
		else if (board[next_ball.y][next_ball.x] == 'O') {
			break;
		}
		//빈 경우
		else {
			cur_ball = next_ball;
		}
	}
	return next_ball;
}
bool sameBallCheck(Point red, Point blue, int dir) {
	//빨간공이 이동해야된다면 true
	//파란공이 이동해야된다면 false
	
	if (dir == 1) {
		//아래 
		//빨간공이 아래 있다.
		if (red.y > blue.y) return false;	//파란공이 이동
		else return true;
	}
	else if (dir == 2) {
		//위
		//빨간공이 아래 있다.
		if (red.y > blue.y) return true;
		else return false;
	}
	else if (dir == 3) {
		//오
		//빨간공이 오른쪽에 있다.
		if (red.x > blue.x) return false; //파란공이 이동
		else return true;
	}
	else if (dir == 4) {
		//왼
		//빨간공이 오른쪽에 있다.
		if (red.x > blue.x) return true;
		else return false;
	}
}
void bfs() {
	queue<pair<int,pair<Point,Point>>>q;		//레드 블루,
	q.push(make_pair(0,make_pair(red_ball, blue_ball)));
	check[red_ball.y][red_ball.x][blue_ball.y][blue_ball.x] = 0;
	while (!q.empty()) {
		int cur_cnt = q.front().first;
		Point cur_red = q.front().second.first;
		Point cur_blue = q.front().second.second;
		q.pop();

		//레드, 블루 방향 이동시킨다..
		for (int i = 1; i <= 4; i++) {
			Point next_red = ballMove(cur_red, i);
			Point next_blue = ballMove(cur_blue, i);
			
			//빨강이랑 파랑이 겹치는 경우
			if (next_red.x == next_blue.x && next_red.y == next_blue.y) {
				//둘다 구멍에 빠진경우
				if (board[next_red.y][next_red.x] == 'O') continue;

				//이동한 방향에따라서 한칸 밀리게 한다.
				if (sameBallCheck(cur_red, cur_blue, i) == false) {
					//파란공이 밀려야된다.
					next_blue = { next_blue.x - m_xy[i][0],next_blue.y - m_xy[i][1] };
				}
				else {
					//빨간공이 밀려야된다.
					next_red = { next_red.x - m_xy[i][0],next_red.y - m_xy[i][1] };
				}

			}
		
				if (board[next_red.y][next_red.x] == 'O'&&board[next_blue.y][next_blue.x] == '.') {
					//빨간공이 빠지고 파랑공은 안빠진경우
					answer = cur_cnt + 1;
					return;
				}
				else if (board[next_red.y][next_red.x] == '.' &&board[next_blue.y][next_blue.x] == 'O') {
					//파란공 빠지고 빨간공 안빠진경우
					continue;
				}
				else {
					//둘다 빈 공간에 있으면 체크해서 이전에 방문했던건지 확인한다.
					if (!check[next_red.y][next_red.x][next_blue.y][next_blue.x]) {
						//cout << next_red.x << ' ' << next_red.y << ' ' << check[cur_red.y][cur_red.x][cur_blue.y][cur_blue.x] + 1 << '\n';
						check[next_red.y][next_red.x][next_blue.y][next_blue.x] =true;
						q.push(make_pair(cur_cnt+1,make_pair(next_red, next_blue)));
					}
				}
		
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
			if (board[i][j] == 'R') {
				red_ball = { j,i };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue_ball = { j,i };
				board[i][j] = '.';
			}

		}
	}
	bfs();
	cout << answer << '\n';

	return 0;
}