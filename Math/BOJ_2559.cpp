#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
int answer;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	int left = 0, right = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		if ((right - left) < K) {
			sum += num;
			right += 1;
			if ((right - left) == K) {
				answer = max(answer, sum);
			}
		}
		else {
			sum -= arr[left];
			sum += num;
			left += 1;
			right += 1;
			if ((right - left) == K) {
				answer = max(answer, sum);
			}
		}
	}
	cout << answer << '\n';

	return 0;
}