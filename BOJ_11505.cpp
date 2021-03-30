#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000000
#define MOD 1000000007
typedef long long ll;
ll arr[MAX];
ll tree[MAX * 4];
int N, M, K;
ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1))%MOD;
}

ll sum(int start, int end, int node, int left, int right) {
	if (end < left || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (sum(start, mid, node * 2, left, right) * sum(mid + 1, end, node * 2 + 1, left, right))%MOD;
}

ll update(int start, int end, int node, int diff, int index) {
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = diff;
	int mid = (start + end) / 2;
	return tree[node] = (update(start, mid, node * 2, diff, index) * update(mid + 1, end, node * 2 + 1, diff, index)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	init(0, N-1, 1);

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, N - 1, 1, c, b-1);
		}
		else if (a == 2) {
			cout << sum(0, N-1, 1, b-1, c-1) << '\n';
		}
	}

	return 0;
}