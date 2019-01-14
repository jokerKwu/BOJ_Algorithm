#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX 26
char board[MAX][MAX];
int visited[MAX][MAX];
int nextDir;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char expr[7] = { '+','1','2','3','4','-','|'};
enum{east=1,south,west,north};
typedef struct {
	int x;
	int y;
}Point;
Point pipeFunc(Point pos,int dir) {
	char curCh = board[pos.y][pos.x];
	Point nextPos=pos;
	switch (curCh) {
	case '+':
		switch (dir) {
		case 1://west->east
			nextPos.x += 1; nextDir = east;
			break;
		case 2://north->south
			nextPos.y += 1; nextDir = south;
			break;
		case 3://east->west
			nextPos.x -= 1; nextDir = west;
			break;
		case 4://south->north
			nextPos.y -= 1; nextDir = north;
			break;
		}
		break;
	case '|':
		if (dir == south) { //north->south
			nextPos.y += 1; nextDir = south;
		}
		else if(dir==north){ //south->north
			nextPos.y -= 1; nextDir = north;
		}
		break;
	case '-':
		if (dir == west) { //east->west
			nextPos.x -= 1; nextDir = west;
		}
		else if(dir==east){ //west->east
			nextPos.x += 1; nextDir = east;
		}
		break;

	case '1':
		if (dir == west) { //east->south
			nextPos.y += 1;nextDir = south;
		}
		else if(dir==north){//south->east
			nextPos.x += 1;nextDir = east;
		}
		break;
	case '2':
		if (dir == south) {//north->east
			nextPos.x += 1;nextDir = east;
		}
		else if(dir==west){//east->north
			nextPos.y -= 1;nextDir = north;
		}
		break;
	case '3':
		if (dir == south) {//north->west
			nextPos.x -= 1;nextDir = west;
		}
		else if(dir==east){//west->north
			nextPos.y -= 1;nextDir = north;
		}
		break;
	case '4':
		if (dir == east) {//west->south
			nextPos.y += 1;nextDir = south;
		}
		else if(dir==north){//south->west
			nextPos.x -= 1;	nextDir = west;
		}
		break;
	}
	return nextPos;
}
bool topCheck(char ch) {
	if (ch == 'M' || ch == 'Z' || ch == '|' || ch == '+' || ch == '1' || ch == '4')
		return true;
	else
		return false;
}
bool bottomCheck(char ch) {
	if (ch == 'M' || ch == 'Z' || ch == '|' || ch == '+' || ch == '3' || ch == '2')
		return true;
	else
		return false;
}
bool leftCheck(char ch) {
	if (ch == 'M' || ch == 'Z' || ch == '-' || ch == '+' || ch == '1' || ch == '2')
		return true;
	else
		return false;
}
bool rightCheck(char ch) {
	if (ch == 'M' || ch == '-' || ch == 'Z' || ch == '+' || ch == '3' || ch == '4')
		return true;
	else
		return false;
}
bool check(Point pos) {
	if (board[pos.y][pos.x] == '|') {
		char ch1 = board[pos.y - 1][pos.x];
		char ch2 = board[pos.y + 1][pos.x];
		if (topCheck(ch1)&&bottomCheck(ch2))
			return true;
		else
			return false;
	}
	if (board[pos.y][pos.x] == '-') {
		char ch1 = board[pos.y ][pos.x-1];
		char ch2 = board[pos.y ][pos.x+1];
		if (leftCheck(ch1) && rightCheck(ch2)) 
			return true;
		else
			return false;
	}
	if (board[pos.y][pos.x] == '+') {
		char ch1 = board[pos.y - 1][pos.x];
		char ch2 = board[pos.y + 1][pos.x];
		char ch3 = board[pos.y][pos.x - 1];
		char ch4 = board[pos.y][pos.x + 1];
		if (topCheck(ch1) && bottomCheck(ch2) && leftCheck(ch3) && rightCheck(ch4))
			return true;
		else
			return false;
	}
	if (board[pos.y][pos.x] == '1') {
		char ch1 = board[pos.y][pos.x+1];
		char ch2 = board[pos.y + 1][pos.x];
		if (rightCheck(ch1) && bottomCheck(ch2))
			return true;
		else
			return false;
	}
	if (board[pos.y][pos.x] == '2') {
		char ch1 = board[pos.y - 1][pos.x];
		char ch2 = board[pos.y ][pos.x+1];
		if (topCheck(ch1) && rightCheck(ch2))
			return true;
		else
			return false;
	}
	if (board[pos.y][pos.x] == '3') {
		char ch1 = board[pos.y ][pos.x-1];
		char ch2 = board[pos.y - 1][pos.x];
		if (leftCheck(ch1)&&topCheck(ch2)) 
			return true;
		else
			return false;
	}
	if (board[pos.y][pos.x] == '4') {
		char ch1 = board[pos.y][pos.x-1];
		char ch2 = board[pos.y + 1][pos.x];
		if (leftCheck(ch1)&&bottomCheck(ch2))
			return true;
		else
			return false;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c,startX=0,startY=0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'M') {//시작 위치를 저장한다
				startY = i;
				startX = j;
			}
		}
	}
	stack<pair<Point,int>>stk;
	visited[startY][startX] =1;
	int curY = 0, curX = 0,dir=0;
	for (int i = 0; i < 4; i++) {//시작위치에서 어느방향에 파이프가 있는지 찾는다.
		int nextY = startY + dy[i];
		int nextX = startX + dx[i];
		if (nextX>=0&&nextY>=0&&nextX<c&&nextY<r&&board[nextY][nextX] != '.') {//파이프가 있다면
			switch (i) {//파이프로부터 흐르는방향을 구하고
			case 0:
				dir = east;
				break;
			case 1:
				dir = south;
				break;
			case 2:
				dir = west;
				break;
			case 3:
				dir = north;
				break;
			}
			Point pos;
			pos.x = nextX; pos.y = nextY;
			stk.push(make_pair(pos, dir));//파이프 위치와 흐르는 방향을 스택에 넣는다.
			visited[pos.y][pos.x] = 1;
		}
	}
	Point erasePos;
		while (!stk.empty()) {//지워진 파이프를 찾기위해서 탐색을 한다.
			Point curPos = stk.top().first;
			int curDir = stk.top().second;
			stk.pop();
			Point pos = pipeFunc(curPos, curDir);
			if (!visited[pos.y][pos.x] && board[pos.y][pos.x] != '.') {
				visited[pos.y][pos.x]++;
				stk.push(make_pair(pos, nextDir));
			}
			else if (visited[pos.y][pos.x] == 1 && board[pos.y][pos.x] == '+') {
				visited[pos.y][pos.x]++;
				stk.push(make_pair(pos, nextDir));
			}
			else {
				visited[pos.y][pos.x]++;
				erasePos = pos;
			}
		}
		bool ok = false;
		int curDir = nextDir;
		for (int i = 0; i < 7; i++) {
			board[erasePos.y][erasePos.x] = expr[i];
			ok = check(erasePos);
			if (ok) {
				cout << erasePos.y + 1 << ' ' << erasePos.x + 1 << ' ' << expr[i] << '\n';
				break;
			}
		}
	return 0;
}