#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
#define MAX 3000000
vector<int> arr;
bool check[MAX];
int leftCache[1<<20], rightCache[1<<20],len;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		len += num;
	}
	// 왼쪽 오른쪽 모든 경우의 수를 구한다.
	for (int bit = 0; bit < (1 << N); bit++) {
		for (int i = 0; i < N; i++) {
			if (bit&(1 << i)) leftCache[bit] += arr[i],rightCache[bit]+=arr[i];
		}
	}
	//전부 비교한다.
	for (int left = 0; left < (1 << N); left++) {
		for (int right = 0; right < (1 << N); right++) {
			int tmp = leftCache[left] - rightCache[right];
			check[abs(tmp)] = true;
		}
	}
	int answer = 0;
	for (int i = 1; i <= len; i++) {
		if (!check[i]) answer++;
	}
	cout << answer << '\n';
	return 0;
}