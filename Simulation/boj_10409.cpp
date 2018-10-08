#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int cnt = 0, res = 0;
	for (int i = 0; i < n; i++) {
		res += v[i];
		if (res <= t)
			cnt++;
		else
			break;
	}
	cout << cnt << '\n';
	return 0;
}