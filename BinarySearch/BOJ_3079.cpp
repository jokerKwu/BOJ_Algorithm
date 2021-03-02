#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, M;
	cin >> N >> M;
	ll maxValue = 0;
	for (int i = 0;i < N;i++) {
		ll num;
		cin >> num;
		arr.push_back(num);
		maxValue = max(num, maxValue);
	}
	ll left = 0, right = maxValue * M;
	ll answer = right;
	while (left <= right) {
		ll mid = (left + right) / 2;
		//mid가 걸린 시간이고  몇명가능한지 계산하자.
		ll value = 0;
		for (int i = 0;i < arr.size();i++) {
			value += (mid / arr[i]);
		}
		if (value < M) {
			left = mid + 1;
		}
		else {
			answer = min(answer, mid);
			right = mid - 1;
		}
	}
	cout << answer << '\n';

	return 0;
}