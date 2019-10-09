#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
#define MAX 1001

using namespace std;
int N, M;
int indegree[MAX], result[MAX];
vector<int>edge[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int K,cur,prev;
		cin >> K;
		cin >> prev;
		for (int j = 1; j < K; j++) {
			cin >> cur;
			indegree[cur]++;
			edge[prev].push_back(cur);
			prev = cur;
		}
	}
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			cout << 0 << '\n';
			return 0;
		}
		
		int node = q.front();
		result[i] = node;
		q.pop();

		for (int j = 0; j < edge[node].size(); j++) {
			if (--indegree[edge[node][j]] == 0) {
				q.push(edge[node][j]);
			}
		}

	}
	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}