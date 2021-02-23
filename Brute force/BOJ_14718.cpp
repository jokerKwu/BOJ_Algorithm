#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K,answer = 987654321;
int a[102], b[102], c[102];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			for (int k = 0;k < N;k++) {
				int ta = a[i], tb = b[j], tc = c[k];
				int cnt = 0;
				for (int l = 0;l < N;l++) {
					if (a[l] <= ta && b[l] <= tb && c[l] <= tc) cnt++;
				}
				if (cnt >= K) answer = min(answer, ta + tb + tc);
			}
		}
	}
	cout << answer << '\n';
	return 0;
}