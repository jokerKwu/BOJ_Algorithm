#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n; cin >> n;
		vector<int> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}

		vector<int> peak;
		for (int i = 1; i < n - 1; i++) {
			if (h[i - 1] < h[i] && h[i] > h[i + 1]) {
				peak.push_back(i);
			}
		}

		int ans = 0;
		for (auto p : peak) {
			int left = 0, right = 0;
			int lh = h[p], rh = h[p];
			for (int l = p - 1; l >= 0; l--) {
				if (lh > h[l]) {
					left++;
					lh = h[l];
				}
				else {
					break;
				}
			}

			for (int r = p + 1; r < n; r++) {
				if (rh > h[r]) {
					right++;
					rh = h[r];
				}
				else {
					break;
				}
			}

			ans += left * right;
		}

		cout << "#" << tc << ' ' << ans << '\n';
	}

	return 0;
}