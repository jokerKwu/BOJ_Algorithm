#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#include<vector>
#include<functional>
using namespace std;
#define MAX 21
typedef pair<int, int>pii;	//x,y
typedef pair<int, pair<int, int>>piii;		//거리 좌표 x,y
typedef pair<int, pair<int, pair<int, int>>> piiii; //이동거리, 좌표, 물고기 크기
int board[MAX][MAX];
bool visited[MAX][MAX];
pii startPos;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, sharkSize = 2, res = 0, eat = 0;
void update() {
	memset(visited, false, sizeof(visited));
}
/*
	벡터 : 현재 아기상어 위치에서 먹을 수 있는 물고기를 저장한다. (거리와,좌표)

	1.우선순위큐를 사용 (거리,x좌표,y좌표) 저장  거리가 짧은것들을 앞으로 정렬 시킨다.
	2.현재 좌표가 물고기인데 먹을 수 있는 물고기이거나 이동 불가능한 물고기라면
	2-1.아기상어보다 작은 물고기라면 벡터에 넣는다.
	2-2.이동 가능한 좌표라면 방문안했다면 큐에 넣는다.
	3. 거리가 가까운 순으로 정렬
	3-1 벡터에서 거리가 짧은 물고기 인덱스로 업데이트
	3-2 짧은 거리가 같다면 주어진 조건에 적합한 인덱스로 업데이트 (위에 있고 왼쪽에 있는 물고기)
	4. 먹을 물고기가 존재한다면 변경해준다.
	5. 먹은 물고기수와 아기상어 사이즈가 같다면 아기상어사이즈 증가시킨다.
*/
bool bfs() {
	priority_queue<piii, vector<piii>, greater<piii>>pq;	//1
	pq.push(make_pair(0, make_pair(startPos.first, startPos.second)));
	visited[startPos.second][startPos.first] = true;
	vector<piiii> v;
	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curPosX = pq.top().second.first;
		int curPosY = pq.top().second.second;
		pq.pop();
		if (board[curPosY][curPosX] != 0 && board[curPosY][curPosX] != 9 && board[curPosY][curPosX] != sharkSize) {//2
			if (sharkSize > board[curPosY][curPosX]) {//2-1
				v.push_back(make_pair(curDist, make_pair(curPosX, make_pair(curPosY, board[curPosY][curPosX]))));
			}
		}
		else {//2-2
			for (int i = 0; i < 4; i++) {
				int nextDist = curDist + 1;
				int nextPosX = curPosX + dx[i];
				int nextPosY = curPosY + dy[i];
				if (nextPosX >= 0 && nextPosY >= 0 && nextPosY < n&&nextPosX < n) {
					if (!visited[nextPosY][nextPosX] && sharkSize >= board[nextPosY][nextPosX]) {
						visited[nextPosY][nextPosX] = true;
						pq.push(make_pair(nextDist, make_pair(nextPosX, nextPosY)));
					}
				}
			}
		}
	}
	sort(v.begin(), v.end());	//3
	int min = 987654;
	int idx = -1;
	for (int i = 0; i < v.size(); i++) {
		if (min > v[i].first) {//3-1
			min = v[i].first;
			idx = i;
		}
		else if (min == v[i].first) {//3-2
			if (v[i].second.second.first < v[idx].second.second.first) {
				idx = i;
			}
			else if (v[i].second.second.first == v[idx].second.second.first) {
				if (v[i].second.first < v[idx].second.first) {
					idx = i;
				}
			}
		}
	}
	if (idx != -1) {	//4
		board[startPos.second][startPos.first] = 0;	//시작위치 물고기를 지우고
		startPos.first = v[idx].second.first;	//먹은 물고기로 시작위치 변경
		startPos.second = v[idx].second.second.first;
		res += v[idx].first;	//거리 추가
		board[startPos.second][startPos.first] = 9;//시작위치 
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				startPos.first = j;		//x좌표
				startPos.second = i;	//y좌표
			}
		}
	}
	bool flag = true;
	while (flag) {
		if (bfs() == false) {//더이상 탐색할게 없으므로 종료
			flag = false;
		}
		else {//5
			eat++;
			if (eat == sharkSize) {
				eat = 0;
				sharkSize++;
			}
			update();
		}
	}
	cout << res << '\n';
	return 0;
}