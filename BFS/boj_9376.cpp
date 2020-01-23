#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<queue>

using namespace std;
#define MAX 104
int H, W;
char board[MAX][MAX];
int mv_board[MAX][MAX][3];			// 죄수1,죄수2, 상근 이동 
bool visited[MAX][MAX][3];
int answer_board[MAX][MAX];
int m_xy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int answer;

typedef struct {
	int x;
	int y;
}Point;
Point s_pos;
vector<Point> p_pos;

void print() {

	for (int k = 0; k < 3; k++) {
		cout << "===================\n";
		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++) {
				cout << mv_board[i][j][k] << ' ';
			}cout << '\n';
		}
	}
}


void bfs(int index) {
	
	queue<Point>q;
	q.push({ p_pos[index] });
	while (!q.empty()) {
		Point cur_pos = q.front();
		int cur_cnt = mv_board[cur_pos.y][cur_pos.x][index];
		q.pop();
		for (int i = 0; i < 4; i++) {

			Point next_pos = { cur_pos.x + m_xy[i][0],cur_pos.y + m_xy[i][1] };

			if (next_pos.x<0 || next_pos.y<0 || next_pos.x>W+1|| next_pos.y>H+1) continue;

			//이동가능한 맵이라면
			if (board[next_pos.y][next_pos.x] == '.'||board[next_pos.y][next_pos.x]=='$'||board[next_pos.y][next_pos.x]=='#') {
				//방문을 안했다면
				if (!visited[next_pos.y][next_pos.x][index]) {
					//문인 경우
					if (board[next_pos.y][next_pos.x] == '#') {
						mv_board[next_pos.y][next_pos.x][index] = cur_cnt + 1;
						visited[next_pos.y][next_pos.x][index] = true;
						q.push(next_pos);
					}
					//빈 경우
					else {
						mv_board[next_pos.y][next_pos.x][index] = cur_cnt;
						visited[next_pos.y][next_pos.x][index] = true;
						q.push(next_pos);
					}
				}
				//방문을 했다면
				else {
					//문인 경우
					if (board[next_pos.y][next_pos.x] == '#'&&mv_board[next_pos.y][next_pos.x][index]-1>cur_cnt) {
						mv_board[next_pos.y][next_pos.x][index] = cur_cnt + 1;
						q.push(next_pos);
					}
					else if((board[next_pos.y][next_pos.x]=='.'||board[next_pos.y][next_pos.x]=='$')&&mv_board[next_pos.y][next_pos.x][index]>cur_cnt){
						mv_board[next_pos.y][next_pos.x][index] = cur_cnt;
						q.push(next_pos);
					}
				}
			}
		}
	}
	
}

int solution() {

	int result = 987654321;
	
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++) {
				answer_board[i][j] += mv_board[i][j][k];
			}
		}
	}
	for (int i = 1; i <= H ; i++) {
		for (int j = 1; j <= W ; j++) {
			if (board[i][j] == '#') answer_board[i][j] -= 2;
			
			if (board[i][j] != '*') {

				result = min(result, answer_board[i][j]);

			}
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		memset(visited, false, sizeof(visited));
		memset(mv_board, 0, sizeof(mv_board));
		memset(answer_board, 0, sizeof(answer_board));
		p_pos.clear();
		cin >> H >> W;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> board[i][j];
				if (board[i][j] == '$') {
					p_pos.push_back({ j,i });
				}
			}
		}

		for (int i = 0; i <= W + 1; i++) board[0][i] = board[H + 1][i] = '.';
		for (int i = 0; i <= H + 1; i++) board[i][0] = board[i][W + 1] = '.';

		//상근이 좌표 넣자
		s_pos.x = 0; s_pos.y = 0;
		p_pos.push_back(s_pos);

		//죄수1 죄수2 상근  bfs 탐색을 돌린다.
		for (int i = 0; i < 3; i++) {
			bfs(i);
		}
		
		//3개 맵 합쳐서 최소값 출력
		cout << solution() << '\n';

	}
	return 0;
}