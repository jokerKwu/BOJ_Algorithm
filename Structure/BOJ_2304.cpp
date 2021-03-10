#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
vector<pii> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int maxHeight = 0;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
		maxHeight = max(b, maxHeight);
	}
	sort(arr.begin(), arr.end());
	int sx = arr[0].first;
	int sy = arr[0].second;
	int answer = 0;
	
	//-> 이렇게 한번
	for (int i = 0;i < N;i++) {
		int nx = arr[i].first;
		int ny = arr[i].second;
		if (sy <= ny) {
			answer += (nx - sx) * sy;
			sx = nx;
			sy = ny;
		}
	}


	// <- 이렇게 한번 해야겠다.
	sx = arr[N - 1].first;
	sy = arr[N - 1].second;
		for (int i = N - 1;i >= 0;i--) {
			int nx = arr[i].first;
			int ny = arr[i].second;
			if (sy < ny) {
				answer += (sx - nx) * sy;
				sx = nx;
				ny = sy;
			}
		}

	cout << answer+ maxHeight << '\n';
	return 0;
}