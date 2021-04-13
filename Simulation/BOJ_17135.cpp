#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define MAX 17
/*
5 5 1
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
int board[MAX][MAX];
int N, M, D;

bool archers[MAX];
int answer;


void print() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << ' ';
		}cout << '\n';
	}
}

//아래로 이동시키는 함수
void downMove() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				int next_y = i + 1;
				if (board[next_y][j] == 2) {
					board[i][j] = 0;
				}
				else {
					board[i][j] = 0;
					board[next_y][j] = 1;
				}
			}
		}
	}
}

//게임 시작 함수
int gameStart() {
	int tmpBoard[MAX][MAX];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			tmpBoard[i][j] = board[i][j];
		}
	}
	int kill = 0;
	int archersPos[3];
	int index = 0;
	for (int i = 0; i < 3; i++) archersPos[i] = -1;
	//궁수 좌표 추출하고
	for (int i = 0; i < M; i++) {
		if (archers[i] == true) {
			archersPos[index] = i;
			index++;
		}
	}
	bool usedArchers[3];
	vector<pair<int,pair<int,pair<int,int>>>> deletePos;	//거리, 아처인덱스, x,y
	//턴을 정해야되는데 N번만큼만 돌면되
	for(int turn = 0; turn < N ; turn++){
		for (int i = 0; i < 3; i++) usedArchers[i] = false;
		deletePos.clear();
		//적을 제거하자.
		for (int y = N-1; y >= (N-1) - D; y--) {
			for (int x = 0; x < M; x++) {
				if (board[y][x] == 1) {//적 발견했어
					//궁수마다 좌표꺼내서 비교
					int ay = N;
					for (int a = 0; a < 3; a++) {
						int ax = archersPos[a];
						int dist = (abs(y - ay) + abs(x - ax));
						//다 넣는걸로?
						if (dist <= D) {
							deletePos.push_back({ dist,{a,{x,y}}});
						}
					}
				}
			}
		}
		sort(deletePos.begin(), deletePos.end());
		//적을 제거한다.
		int cnt = 0;
		for (int i = 0; i < deletePos.size(); i++) {
			if (!usedArchers[deletePos[i].second.first]) {
				usedArchers[deletePos[i].second.first] = true;
				int dx = deletePos[i].second.second.first;
				int dy = deletePos[i].second.second.second;
				if (board[dy][dx] == 1) kill++;
				board[dy][dx] = 0;
				cnt++;
				if (cnt == 3) break;
			}
		}
		//적 이동
		downMove();
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = tmpBoard[i][j];
		}
	}
	
	return kill;
}
//궁수 자리 선택
void dfs(int x, int cnt) {
	if (cnt == 3) {
		//궁수 3마리 선택했으면
		//게임시작
		answer = max(answer,gameStart());
		return;
	}
	if (x == M) return;
	//현재 좌표 선택
	archers[x] = true;
	dfs(x + 1, cnt + 1);
	archers[x] = false;
	
	//현재 좌표 노선택
	dfs(x + 1, cnt);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		board[N][i] = 2;
	}
	
	//dfs로 궁수 자리를 선택하자
	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}