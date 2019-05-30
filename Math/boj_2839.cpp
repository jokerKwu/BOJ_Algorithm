#include<iostream>
#include<algorithm>
using namespace std;
int ans=3001;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int v = N / 5;
	for (int i = v; i >= 0; i--) {
		int f_v = 5 * i;
		int res = N - f_v;
		int t_cnt = 0;
		if (res == 0) {
			ans = min(ans, i);
		}
		else {
			if (res % 3 == 0) {
				ans = min(ans, i + (res / 3));
				break;
			}
			else {
				continue;
			}
		}
	}
	if (ans == 3001) cout << -1 << '\n';
	else cout << ans << '\n';
}