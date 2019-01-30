#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
#define MAX 200001
bool visited[MAX];
int n, k;//¼öºóÀÌ ÁÂÇ¥, µ¿»ý ÁÂÇ¥
int dx[3] = { -1,0,1 };
typedef pair<int, int>pii;//½Ã°£ ÁÂÇ¥
int bfs() {
	queue<pii>q;
	q.push(make_pair(0, n));
	visited[n] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int pos = q.front().second;
		q.pop();
		if (pos == k) {
			return cnt;
		}
		for (int i = 0; i < 3; i++) {
			int nextPos = pos;
			int nextCnt = cnt;
			if (i == 1) {
				nextPos *= 2;
			}
			else {
				nextPos += dx[i];
				nextCnt += 1;
			}

			if (nextPos >= 0 && nextPos <= 200000) {
				if (!visited[nextPos]) {
					visited[nextPos] = true;
					q.push(make_pair(nextCnt, nextPos));
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	int res = bfs();
	cout << res << '\n';
	return 0;
}