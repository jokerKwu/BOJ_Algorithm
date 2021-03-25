#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 26
using namespace std;
char board[MAX][MAX];
typedef struct {
	int x;
	int y;
}Point;
vector<Point> startPos;
int charToInt(char ch) {
	switch (ch) {
	case '|':
		return 0;
	case '-':
		return 1;
	case '+':
		return 2;
	case '1':
		return 3;
	case '2':
		return 4;
	case '3':
		return 5;
	case '4':
		return 6;
	case '.':case 'M': case 'Z':
		return 7;
	}
}
int ch_next_dir[7][4] = {
	{0,1,-1,-1},
	{-1,-1,2,3},
	{0,1,2,3},
	{3,-1,1,-1},
	{-1,3,0,-1},
	{-1,2,-1,0},
	{2,-1,-1,1}
};
int m_xy[4][2] = { {0,-1},{0,1},{-1,0},{1,0} }; //상 , 하, 좌, 우
int N, M;
int visit[MAX][MAX];
bool check[4];
Point erasePos;
void bfs() {
	queue<pair<int,Point>> q;
	for (int i = 0;i < startPos.size();i++) {
		for (int d = 0;d < 4;d++) {
			q.push({ d, startPos[i] });
		}
	}
	while (!q.empty()) {
		int cur_dir = q.front().first;
		Point cur_pos = q.front().second;
		q.pop();
		Point next_pos = { cur_pos.x + m_xy[cur_dir][0] , cur_pos.y + m_xy[cur_dir][1] };
		if (next_pos.x < 0 || next_pos.y < 0 || next_pos.x >= M || next_pos.y >= N) continue;
		if (board[next_pos.y][next_pos.x] == '.') {
			visit[next_pos.y][next_pos.x] += 1;
			if (visit[next_pos.y][next_pos.x] == 2) erasePos = next_pos;
		}
		else {
			int ch_num = charToInt(board[next_pos.y][next_pos.x]);
			if (ch_num == 7) {
				visit[next_pos.y][next_pos.x] += 1;
				if (visit[next_pos.y][next_pos.x] == 2) erasePos = next_pos;
			}
			else {
				int next_dir = ch_next_dir[ch_num][cur_dir];
				if (next_dir != -1) {
					q.push({ next_dir,next_pos });
				}
			}
		}
	}
}
bool shapeCheck(int dir,Point pos) {

	if (pos.x < 0 || pos.y < 0 || pos.x >= M || pos.y >= N) return false;
	if (dir == 0 && (board[pos.y][pos.x] == '|' || board[pos.y][pos.x] == '+' || board[pos.y][pos.x] == '1' || board[pos.y][pos.x] == '4' ||board[pos.y][pos.x] == 'M' || board[pos.y][pos.x] == 'Z')) {
		//상
		return true;
	}
	else if (dir == 1 && (board[pos.y][pos.x] == '|' || board[pos.y][pos.x] == '+' || board[pos.y][pos.x] == '2' || board[pos.y][pos.x] == '3' || board[pos.y][pos.x] == 'M' || board[pos.y][pos.x] == 'Z')) {
		//하
		return true;
	}
	else if (dir == 2 && (board[pos.y][pos.x] == '-' || board[pos.y][pos.x] == '+' || board[pos.y][pos.x] == '1' || board[pos.y][pos.x] == '2' || board[pos.y][pos.x] == 'M' || board[pos.y][pos.x] == 'Z')) {
		//좌
		return true;
	}
	else if(dir == 3 && (board[pos.y][pos.x] == '-' || board[pos.y][pos.x] == '+' || board[pos.y][pos.x] == '3' || board[pos.y][pos.x] == '4' || board[pos.y][pos.x] == 'M' || board[pos.y][pos.x] == 'Z')){
		//우
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> board[i][j];
			if (board[i][j] == 'M'|| board[i][j] == 'Z') {
				startPos.push_back({ j,i });
			}
		}
	}
	bfs();
	cout << erasePos.y+1 <<' '<< erasePos.x+1 << ' ';
	for (int i = 0;i < 4;i++) {
		if (shapeCheck(i,{ erasePos.x + m_xy[i][0], erasePos.y + m_xy[i][1] })) {
			check[i] = true;
		}
	}
	if (check[0] && check[1]  && check[2]  && check[3] ) {
		//상하가 M,Z 인 경우와 좌우가 M,Z인 경우는 체크를 없애야지.
		Point upPos = { erasePos.x + m_xy[0][0], erasePos.y + m_xy[0][1] };
		Point downPos = { erasePos.x + m_xy[1][0], erasePos.y + m_xy[1][1] };
		Point leftPos = { erasePos.x + m_xy[2][0], erasePos.y + m_xy[2][1] };
		Point rightPos = { erasePos.x + m_xy[3][0] , erasePos.y + m_xy[3][1] };
		if ((board[upPos.y][upPos.x] == 'M' || board[upPos.y][upPos.x] == 'Z') && (board[downPos.y][downPos.x] == 'M' || board[downPos.y][downPos.x] == 'Z')) {
			check[0] = false;
			check[1] = false;
		}
		else if ((board[leftPos.y][leftPos.x] == 'M' || board[leftPos.y][leftPos.x] == 'Z') && (board[rightPos.y][rightPos.x] == 'M' || board[rightPos.y][rightPos.x] == 'Z')) {
			check[2] = false;
			check[3] = false;
		}
		//그게 아니라면 + 이거고
		
	}
	
	if (check[0]  && check[1] && check[2]&& check[3] ) {
		cout << "+" << '\n';
	}
	else if (check[0]  && check[1]) {
		cout << "|" << '\n';
	}
	else if (check[2]  && check[3] ) {
		cout << "-" << '\n';

	}
	else if (check[0]&& check[2]) {
		cout << "3" << '\n';
	}
	else if (check[0] && check[3]) {
		cout << "2" << '\n';
	}
	else if (check[1] && check[2]) {
		cout << "4" << '\n';
	}
	else if (check[1] && check[3]) {
		cout << "1" << '\n';
	}
	return 0;
}