#include<iostream>
#include<set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, cnt = 0;
	cin >> n >> m;
	set<int>st;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (m >= num && st.count(m - num) == 0) {
			st.insert(num);
		}
		else if (m >= num) {
			cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
}