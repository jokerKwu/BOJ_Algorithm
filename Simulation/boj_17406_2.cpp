#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 52
int board[MAX][MAX];
bool visited[MAX];
int N, M,K,answer=98765432;
typedef struct {
	int y; //y
	int x; //x
	int s; //크기
}Info;
vector<Info> rotations;
int min_value() {
	int tmp = 987654321;
	for (int i = 1; i <= N; i++) {
		int res = 0;
		for (int j = 1; j <= M; j++) {
			res += board[i][j];
		}
		tmp = min(tmp, res);
	}
	return tmp;
}

void array_rotation(Info tmp) {
	
	int sx, sy, dx, dy,next_value;
	for (int size = 1; size <= tmp.s; size++) {
		//->
		//시작위치 , 종료위치
		sx = tmp.x - size;
		sy = tmp.y - size;
		dx = tmp.x + size;
		next_value = board[sy][dx];
		for (int i = dx; i> sx; i--) {
			board[sy][i] = board[sy][i-1];
		}

		//↓
		sx = tmp.x + size;
		sy = tmp.y - size;
		dy = tmp.y + size;
		int next_value2 = board[dy][dx];
		for (int i = dy; i > sy+1; i--) {
			board[i][sx] = board[i - 1][sx];
		}
		board[sy + 1][sx] = next_value;

		//<-
		sx = tmp.x + size;
		sy = tmp.y + size;
		dx = tmp.x - size;
		next_value = board[sy][dx];
		for (int i = dx; i < sx -1; i++) {
			board[sy][i] = board[sy][i + 1];
		}
		board[sy][sx - 1] = next_value2;
		//↑
		sx = tmp.x - size;
		sy = tmp.y + size;
		dy = tmp.y - size;
		for (int i = dy; i < sy - 1; i++) {
			board[i][sx] = board[i + 1][sx];
		}
		board[sy - 1][sx] = next_value;
	}

}


void backtracking(int cnt) {
	if (cnt == rotations.size()) {
		answer = min(answer, min_value());
		return;
	}
	for (int i = 0; i < rotations.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			//맵 복사
			int tmp_board[MAX][MAX];
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					tmp_board[i][j] = board[i][j];
				}
			}
			array_rotation(rotations[i]);
			backtracking(cnt + 1);
			visited[i] = false;

			//맵 원상 복귀
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					board[i][j] = tmp_board[i][j];
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M>>K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		Info tmp;
		cin >> tmp.y >> tmp.x >> tmp.s;
		rotations.push_back(tmp);
	}
	backtracking(0);
	cout << answer << '\n';
	return 0;
}