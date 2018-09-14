#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321
typedef long long ll;
vector<ll> arr, tree;
ll Init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(Init(start, mid, node * 2) , Init(mid + 1, end, node * 2 + 1));
}
ll Find(int start, int end, int node,int left, int right) {
	if (left > end || right < start) return INF;	//범위에서 벗어난 경우
	if (start>=left&&end<=right) return tree[node]; //범위안에 포함되는 경우
	int mid = (start + end) / 2;
	return min(Find(start, mid, node * 2, left, right), Find(mid + 1, end, node * 2 + 1, left, right));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		arr.push_back(num);
	}
	tree.resize(n * 4);
	Init(0, n - 1, 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ll res = 0;
		res=Find(0, n-1,1, a-1, b-1);
		cout << res << '\n';
	}
	return 0;
}