#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
4
120 110 140 150
485
*/

int N, M;
vector<int> arr;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int maxValue = 0;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		maxValue = max(maxValue, num);
	}
	cin >> M;
	int left = 0, right = maxValue;
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0;i < arr.size();i++) {
			if (mid < arr[i]) {
				sum += mid;
			}
			else {
				sum += arr[i];
			}			
		}
		cout << sum << '\n';
		if (sum <= M) {
			left = mid + 1;
			answer = max(answer, mid);
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer << '\n';
	return 0;
}