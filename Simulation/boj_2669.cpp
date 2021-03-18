/*
입력은 네 줄이며, 각 줄은 직사각형의 위치를 나타내는 네 개의 정수로 주어진다. 첫 번째와 두 번째의 정수는 사각형의 왼쪽 아래 꼭짓점의 x좌표, y좌표이고 세 번째와 네 번째의 정수는 사각형의 오른쪽 위 꼭짓점의 x좌표, y좌표이다. 모든 x좌표와 y좌표는 1이상이고 100이하인 정수이다.
1 2 4 4   x1 y1 x2 y2
2 3 5 7
3 1 6 5
7 3 8 6
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 102
bool board[MAX][MAX];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int answer = 0;
	for (int t = 0;t < 4;t++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1;i < y2;i++) {
			for (int j = x1;j < x2;j++) {
				if (!board[i][j]) {
					answer++;
					board[i][j] = true;
				}
			}
		}
	}
	cout << answer << '\n';
	
	

	return 0;
}