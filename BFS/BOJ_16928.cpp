#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int change[102];
int visit[102];
int main() {
	cin >> N >> M;
	for (int i = 1; i <= 100; i++) {
		change[i] = i;
		visit[i] = 102;
	}
	for (int i = 0; i < N+M; i++) {
		int x, y;
		cin >> x >> y;
		change[x] = y;
	}
	
	visit[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cn = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nn = cn + i;
			if (nn < 101) {
				if (change[nn] != nn) {
					nn = change[nn];
				}
				if(visit[nn] == 102){
					visit[nn] = visit[cn] + 1;
					q.push(nn);
				}
			}
		}
	}
	cout << visit[100] << '\n';

	return 0;
}