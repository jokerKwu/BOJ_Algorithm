#include<iostream>
#include<queue>
using namespace std;
int N,answer;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		answer += (sum * num);
		sum += num;
	}
	cout << answer << '\n';

	return 0;
}