#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
#include<functional>
#define MAX 101002
using namespace std;
vector<int>edge[MAX];
bool visited[MAX];
int n, k, m;
typedef pair<int, int>pii;	//횟수, 노드
int bfs() {
	priority_queue<pii, vector<pii>, greater<pii>>pq;//연결 노드
	pq.push(make_pair(1, 1));
	visited[1] = true;
	while (!pq.empty()) {
		int curCnt = pq.top().first;
		int curNode = pq.top().second;
		if (curNode == n) {
			return curCnt;
		}
		pq.pop();
		for (int i = 0; i < edge[curNode].size(); i++) {
			int nextNode = edge[curNode][i];
			int nextCnt = curCnt;
			if (nextNode < 100001) {
				nextCnt += 1;
			}
			if (!visited[nextNode]) {
				visited[nextNode] = true;
				pq.push(make_pair(nextCnt, nextNode));
			}
			
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int num;
			cin >> num;
			edge[100001 + i].push_back(num);
			edge[num].push_back(100001 + i);
		}
	}
	int res = bfs();
	cout << res << '\n';
	return 0;
}
