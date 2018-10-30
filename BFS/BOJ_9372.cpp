#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#define MAX 1001
bool visited[MAX];	//방문 했는지 체크
int bfs(vector<int>v[MAX]) {
	memset(visited, false, sizeof(visited));
	queue<int>q;
	q.push(1);
	int ans = 0;
	while (!q.empty()) {
		int currentNode = q.front();	
		q.pop();
		if (!visited[currentNode]) {	//방문했는지 체크
			visited[currentNode] = true;
			ans++;
			for (int i = 0; i < v[currentNode].size(); i++) {	//현재 노드에서 연결되어있는 노드 꺼낸다.
				int nextNode = v[currentNode][i];
				if (!visited[nextNode])	//연결된 노드가 방문 안한 노드이면 q에 집어넣는다.
					q.push(nextNode);
			}
		}
	}
	return ans-1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n, m;
		cin >> n >> m;
		vector<int>v[MAX];
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
		}
		int ans=bfs(v);
		cout << ans << '\n';
	}
	return 0;
}