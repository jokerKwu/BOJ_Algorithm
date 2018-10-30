#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#define MAX 100001
bool visited[MAX];
int a, b, n, m,ans;
typedef pair<int, int>pii;	// 카운트 , 위치
bool rangeCheck(int pos) {
	return (pos >= 0 && pos < MAX) ? true : false;	
}
void bfs() {
	priority_queue<pii,vector<pii>,greater<pii>> pq;		
	pq.push(make_pair(0, n));
	while (!pq.empty()) {
		int currentPos = pq.top().second;
		int currentCnt = pq.top().first;
		if (currentPos == m) {
			ans = currentCnt;
			break;
		}
		pq.pop();
		if (!visited[currentPos]) {
			visited[currentPos] = true;
			int nextPos = currentPos;
			if (rangeCheck(nextPos+1)&&!visited[nextPos + 1]) {		// +1 이동
				pq.push(make_pair(currentCnt+1,nextPos+1));
			}if (rangeCheck(nextPos-1)&&!visited[nextPos - 1]) {	// -1 이동
				pq.push(make_pair(currentCnt + 1, nextPos - 1));

			}if (rangeCheck(nextPos+a)&&!visited[nextPos + a]) {	// +a 이동
				pq.push(make_pair(currentCnt + 1, nextPos + a));

			}if (rangeCheck(nextPos+b)&&!visited[nextPos + b]) {	// +b 이동
				pq.push(make_pair(currentCnt +1, nextPos + b));

			}if (rangeCheck(nextPos-a)&&!visited[nextPos - a]) {	// -a 이동
				pq.push(make_pair(currentCnt + 1, nextPos - a));

			}if (rangeCheck(nextPos - b) && !visited[nextPos - b]) {	// -b 이동
				pq.push(make_pair(currentCnt + 1, nextPos -b));

			}if (rangeCheck(nextPos*a) && !visited[nextPos*a]) {	// 현재좌표*a 이동
				pq.push(make_pair(currentCnt +1, nextPos *a));

			}if (rangeCheck(nextPos*b) && !visited[nextPos*b]) {	//현재좌표*b 이동
				pq.push(make_pair(currentCnt +1, nextPos *b));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> n >> m;
	bfs();
	cout << ans << '\n';
	return 0;
}