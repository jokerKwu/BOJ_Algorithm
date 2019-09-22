#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define MAX 128	

int N;
int board[MAX][MAX];
int answer[2];
//체크하는 함수
bool checkFunction(int x, int y, int size) {
	int value = board[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (board[i][j] != value) return false;
		}
	}
	return true;
}

//나누는 함수
void divideFunction(int x, int y, int size) {
	
	//1인경우에는 종료시킨다
	if (size == 1) {
		answer[board[y][x]]++;
		return;
	}
	//체크해서 모두 같다면 그냥 종료 시키고
	if (checkFunction(x, y, size)) {
		answer[board[y][x]]++;
		return;
	}
	//다른경우에는 반을 나눈다.
	else {
		int nSize = size / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int sx = x +(nSize*j);
				int sy = y + (nSize*i);
				divideFunction(sx, sy, nSize);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	divideFunction(0, 0, N);
	cout << answer[0] << '\n';
	cout << answer[1] << '\n';

	return 0;
}