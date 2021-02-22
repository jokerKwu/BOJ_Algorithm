/*
* 
* 4 4 2 1
1 2
1 3
2 3
2 4

*/

#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
#define MAX 300002
#define INF 987654321
int N, M, D, S;
typedef pair<int, int> pii; // 거리, 노드
vector<int> edge[MAX];
int dist[MAX];
vector<int> answer;

void dijkstra() {
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({ 0,S });
	dist[S] = 0;
	while (!pq.empty()) {
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		if (cur_dist == D) {
			answer.push_back(cur_node);
			continue;
		}
		for (int i = 0;i < edge[cur_node].size();i++) {
			int next_dist = cur_dist + 1;
			int next_node = edge[cur_node][i];
			if (dist[next_node] > next_dist && D >= next_dist) {
				dist[next_node] = next_dist;
				pq.push({ next_dist,next_node });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> D >> S;
	for (int i = 1;i <= N;i++) dist[i] = INF;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	dijkstra();
	sort(answer.begin(), answer.end());
	if (answer.size() == 0) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0;i < answer.size();i++) cout << answer[i] << '\n';
	}
	return 0;
}