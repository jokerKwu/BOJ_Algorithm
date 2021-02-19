#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 20
int board[MAX][MAX];
bool visit[MAX][MAX][4];
typedef struct {
	int x;
	int y;
}Point;
int answer = 0;
Point answer_pos;
int m_xy[4][2] = { {0,1},{1,0},{1,1},{-1,1} };
bool rangeCheck(Point pos) {
	if (0 <= pos.x && 0 <= pos.y && 19 > pos.x && 19 > pos.y) return true;
	else return false;
}
bool bfs() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					if (!visit[i][j][k]) {
						int l = 1;
						vector<pair<int,int>> arr;
						visit[i][j][k] = true;
						arr.push_back({ j,i });
						Point next_pos = { j + (m_xy[k][0] * l),i + (m_xy[k][1] * l) };
						while (rangeCheck(next_pos)==true&&board[i][j] == board[next_pos.y][next_pos.x]) {
							l++;
							arr.push_back({ next_pos.x,next_pos.y });
							visit[next_pos.y][next_pos.x][k] = true;
							next_pos = { j + (m_xy[k][0] * l),i + (m_xy[k][1] * l) };
						}
						if (arr.size() == 5) {
							sort(arr.begin(), arr.end());
							cout << board[i][j] << '\n';
							cout << arr[0].second + 1 << ' ' << arr[0].first + 1 << '\n';
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}
	if (!bfs()) cout << 0 << '\n';

	return 0;
}