#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;
#define WIDTH 6
#define HEIGHT 12
string map[HEIGHT];
bool visited[HEIGHT][WIDTH];		
int cnt;
typedef pair<int, int> pii;		//y ,x
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool bfs() {
	queue<pii>q;
	bool chainBoom = false;
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++) {
			// i , j 에 좌표에 글자가 색깔인지 체크 
			bool charCheck = (map[i][j] == 'R') || (map[i][j] == 'P') || (map[i][j] == 'Y') || (map[i][j] == 'B') || (map[i][j] == 'G');
			if (charCheck&&!visited[i][j]) {//문자이고 방문을 안했다면 큐에 추가한다.
				vector<pii>boom;
				int charCnt = 0;	//방문한 문자열을 카운팅하는 변수
				q.push(make_pair(i, j));
				while (!q.empty()) {
					//큐 맨앞에 좌표를 꺼낸다.
					int currentY = q.front().first;	
					int currentX = q.front().second;
					char currentChar = map[currentY][currentX];	//큐 맨앞에 좌표에 글자 저장
					boom.push_back(make_pair(currentY, currentX));	//터트릴 문자에 좌표를 벡터에 저장
					charCnt++;	
					visited[currentY][currentX] = true;		//방문체크
					q.pop();
					for (int i = 0; i < 4; i++) {	//이동 가능한 4방향을 탐색
						int nextY = currentY + dy[i];
						int nextX = currentX + dx[i];
						//다음 좌표가 맵 범위안에 있는지 체크
						bool range = (nextY >= 0) && (nextY < HEIGHT) && (nextX >= 0) && (nextX < WIDTH);
						//맵안에 있고, 다음 좌표 글자랑 현재 좌표 글자가 같고 방문을 안한 좌표라면 큐에 넣는다.
						if (range&&currentChar == map[nextY][nextX] && !visited[nextY][nextX]) {
							q.push(make_pair(nextY, nextX));
						}
					}
				}
				if (charCnt >= 4) {
					for (int i = 0; i < boom.size(); i++) {
						map[boom[i].first][boom[i].second] = '.';		//터트리고 빈칸으로 바꾼다.
					}
					chainBoom = true;
				}
			}
		}
	}
	return chainBoom ? true : false;		//4개이상 터트린게 있다면 true 없다면 false
}
void update() {
	for (int i = 0; i < WIDTH; i++) {
		int emptyCnt = 0;
		for (int j = HEIGHT - 1; j >= 0; j--) {	//y축부터 이동
			if (map[j][i] == '.')		//비어있다면 카운트
				emptyCnt++;
			else {
				map[j + emptyCnt][i] = map[j][i];
				if(emptyCnt!=0)	//비어있는칸이 0이아니라면  그 위치를 지운다.
					map[j][i] = '.';
			}
		}
	}
	//방문 초기화
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			visited[i][j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}
	memset(visited, false, sizeof(visited));


	while (bfs()) {
		update();//블록 위치 이동과 방문 초기화도 해줘야된다.
		cnt++;	//연쇄 횟수 카운트
	}
	cout << cnt << '\n';
	return 0;
}