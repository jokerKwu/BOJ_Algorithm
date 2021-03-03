#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> arr;
	ll left = 0, right = 2000000000LL * 30LL;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	ll answer = 0;
	if (N <= M) {
		cout << N << '\n';
		return 0;
	}
	else {
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll sum = 0;
			for (int i = 0; i < M; i++) {
				sum += (mid / arr[i]);
			}
			if (sum < N) {
				left = mid + 1;
			}
			else {
				answer = mid;
				right = mid - 1;
			}
		}
		 
		ll children = M;
		for (int i = 0; i < M; i++)
			children += (answer - 1) / arr[i];
		
		
		for (int i = 0; i < M; i++) {
			if (answer % arr[i] == 0)
				children++;
			if (children == N) {
				cout << i + 1 << '\n';
				return 0;
			}
		}
	}
	return 0;
}
