#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;
#define MAX 11
bool visited[MAX];
typedef pair<int, int>pii;
int maxDist;
void dfs(int startNode,vector<int>edge[MAX],int dist) {
	visited[startNode] = true;
	if (maxDist < dist)//탐색한 경로가 가장 길다면 업데이트 해준다.
		maxDist = dist;
	for (int i = 0; i < edge[startNode].size(); i++) {//연결되어 있는 노드들을 dfs로 탐색을 한다.
		int nextNode = edge[startNode][i];	//다음 노드 
		int nextDist = dist + 1;			
		if (!visited[nextNode]) {
			dfs(nextNode, edge, nextDist);	//다음 노드 탐색
			visited[nextNode] = false;		//다음 노드를 방문을 제거한다. 
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		int n, m;
		vector<int>edge[MAX];	//간선 저장 변수
		int res = 0;
		maxDist = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);	//무방향이므로 양쪽으로 저장
			edge[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) { //시작위치를 n개 확인한다.
			memset(visited, false, sizeof(visited));
			dfs(i,edge,1);
			if (res < maxDist)
				res = maxDist;
		}
		cout <<'#'<<tc<<' '<<res << '\n';
	}

	return 0;
}