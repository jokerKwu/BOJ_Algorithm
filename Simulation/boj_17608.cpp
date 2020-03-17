#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	int tmp = arr[N - 1];
	int answer = 1;
	for (int i = N-1; i >= 0; i--) {
		if (tmp < arr[i]) {
			tmp = arr[i];
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}