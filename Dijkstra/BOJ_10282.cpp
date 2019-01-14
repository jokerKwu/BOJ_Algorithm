#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAX 10001
bool visited[MAX];
int valueSave[MAX];
int n, d, c,cnt;
typedef pair<int, int>pii;		//시간 ,연결 노드
void initFunction() {
	memset(visited, false, sizeof(visited));
	memset(valueSave, 0, sizeof(valueSave));
	cnt = 0;
}
/*
기본 로직
시간 짧은 순으로 큐에서 꺼내서 컴퓨터 방문이 가능하다면 
컴퓨터 수를 카운트 하고 최단 시간으로 방문 한것이므로 
배열에 컴퓨터번호 인덱스에 최단 시간을 저장한다.
종료후 배열에 들어있는 시간중 최대값을 출력한다.

*/
void bfs(int startNode, vector<pii>edge[MAX]) {
	priority_queue<pii,vector<pii>,greater<pii>>pq;//시간,연결 노드
	pq.push(make_pair(0,startNode));
	while (!pq.empty()) {
		int curSecond = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (!visited[curNode]) {
			visited[curNode] = true;
			cnt++;	//감염된 컴퓨터 카운트
			valueSave[curNode] = curSecond;	//감염된 컴퓨터 시간을 저장
			for (int i = 0; i < edge[curNode].size(); i++) {
				int nextNode = edge[curNode][i].second;
				if (!visited[nextNode]) {
					int nextSecond = curSecond + edge[curNode][i].first;
					pq.push(make_pair(nextSecond, nextNode));
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		vector<pii> edge[MAX];
		initFunction();
		int a, b, s;
		
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			edge[b].push_back(make_pair(s, a));
		}
		bfs(c,edge);
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (res < valueSave[i])
				res = valueSave[i];
		}
		cout <<cnt<<' '<<res << '\n';
	}
	return 0;
}