#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define MAX 21
int board[MAX][MAX];
bool check[MAX][MAX];	//합쳤는지 체크
int dx[4] = { 0,1,0,-1 };	//오른쪽 왼쪽
int dy[4] = { -1,0,1,0 };	//위 아래
enum{Bup=0,Bright,Bdown,Bleft};
void print(int n) {//출력 함수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cout << board[i][j] << ' ';
		}cout << '\n';
	}
}
int dirCalc(string str) {//방향 숫자로 변경해주는 함수 인덱스로 활용
	if (str == "up") return 0;
	else if (str == "right") return 1;
	else if (str == "down") return 2;
	else return 3;
}
bool rangeCheck(int x, int y, int dir, int n) {//방향마다 제한된 범위 체크
	if (dir == Bup) {
		if (y > 0) return true;
		else return false;
	}
	else if (dir == Bright) {
		if (x < n - 1) return true;
		else return false;
	}
	else if (dir == Bdown) {
		if (y < n - 1) return true;
		else return false;
	}
	else {
		if (x > 0) return true;
		else return false;
	}

}
bool moveCheck(int x,int y, int dir,int n) {//이동가능한지 체크
	if (rangeCheck(x, y, dir, n)) {
		if (board[y][x]!=0&&board[y + dy[dir]][x + dx[dir]] == 0 || (board[y][x] == board[y + dy[dir]][x + dx[dir]] && board[y + dy[dir]][x + dx[dir]])) {//비어있거나 같은 숫자이고 합쳐진 숫자가 아니라면
			return true;
		}
	}
	return false;
}
void moveFunc(int ux, int uy,int dirNum,int n) {//현재 좌표에서 방향으로 이동하는 함수
	while (moveCheck(ux, uy, dirNum, n)) {
		if (board[uy + dy[dirNum]][ux + dx[dirNum]] == board[uy][ux] && !check[uy + dy[dirNum]][ux + dx[dirNum]] && !check[uy][ux]) {
			board[uy + dy[dirNum]][ux + dx[dirNum]] += board[uy][ux];
			board[uy][ux] = 0;
			check[uy + dy[dirNum]][ux + dx[dirNum]] = true;
		}
		else if (rangeCheck(ux,uy,dirNum,n)&& board[uy + dy[dirNum]][ux + dx[dirNum]] == 0) {
			board[uy + dy[dirNum]][ux + dx[dirNum]] += board[uy][ux];
			board[uy][ux] = 0;
		}
		if (dirNum == Bup) uy--;
		else if (dirNum == Bright) ux++;
		else if (dirNum == Bdown) uy++;
		else ux--;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		memset(board, 0, sizeof(board));
		memset(check, false, sizeof(check));
		int n;
		string dir;
		cin >> n >> dir;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		int dirNum = dirCalc(dir);
		if (dirNum == Bup) {	//방향에따라 반복문 실행
			for (int x = 0; x < n; x++) {
				for (int y = 1; y < n; y++) {
					moveFunc(x, y, dirNum, n);

				}
			}
		}
		else if (dirNum == Bright) {
			for (int y = 0; y < n; y++) {
				for (int x = n - 2; x >= 0; x--) {
					moveFunc(x, y, dirNum, n);
				}
			}
		}
		else if (dirNum == Bdown) {
			for (int x = 0; x < n; x++) {
				for (int y = n - 2; y >= 0; y--) {
					moveFunc(x, y, dirNum, n);
				}
			}
		}
		else {
			for (int y = 0; y < n; y++) {
				for (int x = 1; x < n; x++) {
					moveFunc(x, y, dirNum, n);
				}
			}
		}
		cout << '#' << tc << '\n';
		print(n);
	}
	return 0;
}