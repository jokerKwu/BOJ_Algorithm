#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> pii;
#define MAX 100003
bool visit[MAX];
vector<pair<int, int>> edge[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	long long answer = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	int cnt = 1;
	visit[1] = true;
	for (int i = 0; i < edge[1].size(); i++) {
		pq.push({ edge[1][i].second,edge[1][i].first });
	}
	while (!pq.empty()) {
		pii c_info = pq.top();
		pq.pop();
		if (!visit[c_info.second]) {
			cnt++;
			visit[c_info.second] = true;
			for (int i = 0; i < edge[c_info.second].size(); i++) {
				if (!visit[edge[c_info.second][i].first]) {
					pq.push({ edge[c_info.second][i].second,edge[c_info.second][i].first });
				}
			}
		}
		else {
			answer += c_info.first;
		}
	}
	
	if (cnt != N) answer = -1;
	cout << answer << '\n';
	return 0;
}