#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
#define MAX 251
int r, c;
typedef pair<int, int>pii;	// x,y
vector<pii>vs,ks;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char board[MAX][MAX];	//그래프 변수
bool visited[MAX][MAX];	//방문 체크 변수
int ansVCnt, ansKCnt;
void bfs() {
	queue<pii>q;
	for (int i = 0; i < vs.size(); i++) {
		int posX = vs[i].first;	//늑대 좌표 저장
		int posY = vs[i].second;
		int tmpVCnt = 0, tmpKCnt = 0;
		q.push(make_pair(posX, posY));
		while (!q.empty()) {
			int currentX = q.front().first;
			int currentY = q.front().second;
			q.pop();
			if (!visited[currentY][currentX]) {	
				visited[currentY][currentX] = true;
				if (board[currentY][currentX] == 'v')	//방문 안한 늑대라면 카운트
					tmpVCnt++;
				if(board[currentY][currentX]=='k')	//방문 안한 양 카운트
					tmpKCnt++;
				for (int i = 0; i < 4; i++) {
					int nextX = currentX + dx[i];
					int nextY = currentY + dy[i];
					if (!visited[nextY][nextX]&&board[nextY][nextX] == '.') { //방문 안한 빈공간인 경우
						q.push(make_pair(nextX, nextY));
					}
					else if (!visited[nextY][nextX]&&board[nextY][nextX] == 'k') {	//방문안한 양인 경우
						q.push(make_pair(nextX, nextY));
					}
					else if (!visited[nextY][nextX]&&board[nextY][nextX] == 'v') {	//방문 안한 늑대인 경우
						q.push(make_pair(nextX, nextY));
					}
				}
			}
		}
		//양이랑 늑대 카운트 비교해서 최종 값에 저장
		if (tmpVCnt >= tmpKCnt) {//늑대가 양보다 수가 많거나 같은경우
			ansVCnt += tmpVCnt;
		}
		else {//양이 늑대보다 많은경우
			ansKCnt += tmpKCnt;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'v') {	// 늑대인 경우 따로 저장
				vs.push_back(make_pair(j, i));
			}
			else if (board[i][j] == 'k') {	// 양인 경우 따로 저장
				ks.push_back(make_pair(j, i));
			}
		}
	}
	bfs();
	for (int i = 0; i < vs.size(); i++) {//방문 안한 늑대 체크
		int posX = vs[i].first;
		int posY = vs[i].second;
		if (!visited[posY][posX])
			ansVCnt++;
	}
	for (int i = 0; i < ks.size(); i++) {//방문 안한 양 체크
		int posX = ks[i].first;
		int posY = ks[i].second;
		if (!visited[posY][posX])
			ansKCnt++;
	}
	cout << ansKCnt << ' ' << ansVCnt << '\n';
	return 0;
}