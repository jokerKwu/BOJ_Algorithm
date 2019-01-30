#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<functional>
#include<algorithm>
#include<set>
using namespace std;
#define MAX 501
#define INF 98765432
bool visited[MAX];	//방문 노드 체크
int board[MAX];	//이전 방문 기록
typedef pair<int, pair<int,int>>piii;	//거리 , 노드번호, 인덱스번호
typedef pair<int, int>pii;	//거리, 노드번호
vector<pii>edge[MAX];	//연결 노드 , 값
vector<pii>reverseEdge[MAX];
int bfs(int startNode, int distNode) {
	board[startNode] = 0; board[distNode] = 0;
	memset(visited, false, sizeof(visited));
	priority_queue < pii,vector<pii>,greater<pii>>pq;
	pq.push(make_pair(0, startNode));
	while (!pq.empty()) {
		int curD = pq.top().first;
		int curN = pq.top().second;
		pq.pop();
		if (!visited[curN]) {
			visited[curN] = true;
			board[curN] = curD;
			for (int i = 0; i < edge[curN].size(); i++) {
				int nextN = edge[curN][i].first;
				int nextD = curD + edge[curN][i].second;
				if (!visited[nextN]&&edge[curN][i].second!=INF) {
					pq.push(make_pair(nextD, nextN));
				}
			}
		}
	}
	return board[distNode];
}
void removeNode(int startNode, int distNode,int minValue) {
	queue<pii>q;//거리, 노드
	q.push(make_pair(minValue, distNode));
	while (!q.empty()) {
		int curD = q.front().first;
		int curN = q.front().second;
		q.pop();
		for (int i = 0; i < reverseEdge[curN].size(); i++) {
			int nextN = reverseEdge[curN][i].first;
			int nextD = reverseEdge[curN][i].second;
			if (curD - nextD == board[nextN]) {
				for (int i = 0; i < edge[nextN].size(); i++) {
					if (edge[nextN][i].first == curN) {	//간선 제거
						edge[nextN][i].second = INF;
						break;
					}
				}
				q.push(make_pair(curD - nextD, nextN));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	while (n != 0 && m != 0) {
		int s=0,d=0;
		cin >>s>>d;
		//초기화작업
		for (int i = 0; i < MAX; i++) {
			board[i] = 0;
			edge[i].clear();
			reverseEdge[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int node1, node2, dist;
			cin >> node1 >> node2 >> dist;
			edge[node1].push_back(make_pair(node2, dist));
			reverseEdge[node2].push_back(make_pair(node1, dist));
		}
		int minValue=bfs(s, d);
		removeNode(s, d,minValue);
		int res=bfs(s, d);
		if (res == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << res << '\n';
		}
		cin >> n >> m;
	}
	return 0;
}