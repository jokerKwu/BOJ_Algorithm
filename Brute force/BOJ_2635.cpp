#include<iostream>
#include<vector>
using namespace std;
vector<int> arr,answer;
/*
8
100 62 38 24 14 10 4 6
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		arr.clear();
		int num1 = N;
		int num2 = i;
		arr.push_back(num1);
		while (num2 >= 0) {
			arr.push_back(num2);
			int tmp = num1 - num2;
			num1 = num2;
			num2 = tmp;
		}
		if (arr.size() > answer.size()) {
			answer.clear();
			answer = arr;
		}
	}
	cout << answer.size() << '\n';
	for (int i = 0;i < answer.size();i++) {
		cout << answer[i] << ' ';
	}cout << '\n';

	return 0;
}