#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1002
typedef pair<int, int> pii;
vector<pii> arr;
int p[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back({ num,i });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0;i < arr.size();i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
		p[arr[i].second] = i;
	}
	for (int i = 0;i < N;i++) {
		cout << p[i] << ' ';
	}cout << '\n';

	return 0;
}