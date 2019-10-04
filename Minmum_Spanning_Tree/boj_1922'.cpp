#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<functional>

using namespace std;
#define MAX 1002

int N, M;
int res;
typedef pair<int, int>pii;	//비용 , 도착노드
vector<pii>edge[MAX];
bool visited[MAX];
int bfs() {
	int res = 0;
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push(make_pair(0,1));
	while (!pq.empty()) {
		int cNode = pq.top().second;
		int cValue = pq.top().first;
		pq.pop();
		if (!visited[cNode]) {
			res += cValue;
			visited[cNode] = true;

			for (int i = 0; i < edge[cNode].size(); i++) {
				int nNode = edge[cNode][i].second;
				int nValue = edge[cNode][i].first;
				if (!visited[nNode]) {
					pq.push(make_pair(nValue, nNode));
				}
			}
		}
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(c, b));
		edge[b].push_back(make_pair(c, a));
	}
	cout<<bfs()<<'\n';

	return 0;
}