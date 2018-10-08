#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 101
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = arr[i] + arr[j] + arr[k];
				if (ans < temp&&temp <= m) {
					ans = temp;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}