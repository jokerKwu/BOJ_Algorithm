#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10001
#define F 0
int parent[MAX];
int N, M, K;
typedef pair<int, int>pii;
vector<pii>v;

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

int Find(int x) {

	if (parent[x] == x) return x;
	
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y) parent[x] = y;
	else parent[y] = x;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++) {
		int value;
		cin >> value;
		v.push_back(make_pair(value, i));
	}
	sort(v.begin(), v.end());
	init();
	parent[0] = F;
	int res = 0;
	bool pass = true;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 0; i < N; i++) {
		int node = v[i].second;
		int value = v[i].first;
		int x = Find(node);

		if (parent[node] == F) continue;
		else if (parent[node] != F&&K>=value) {
			res += value;
			K -= value;
			Union(0, node);
		}
		else {
			pass = false;
			break;
		}
	}
	if (pass) cout << res << '\n';
	else cout << "Oh no\n";

	return 0;
}