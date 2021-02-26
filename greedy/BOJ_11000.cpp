#include<iostream>
#include<vector>
#include<functional>
#include<queue>
#include<algorithm>
using namespace std;
int N;
typedef pair<int, int> pii;
vector<pii> arr;  // 시작 종료
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int answer = 0;
	for (int i = 0;i < arr.size();i++) {
		if (pq.empty()) {
			pq.push(arr[i].second);
			answer = max(answer, int(pq.size()));
		}
		else {
			while (!pq.empty()&&pq.top() <= arr[i].first) pq.pop();
			pq.push(arr[i].second);
			answer = max(answer, int(pq.size()));
		}
	}
	cout << answer << '\n';
	return 0;
}