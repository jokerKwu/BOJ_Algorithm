#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, C,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> C;

	vector<int>houses;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		houses.push_back(num);
	}

	sort(houses.begin(), houses.end());

	//간격
	int left = 1;	//최소 간격 길이
	int right = houses[N - 1] - houses[0];	//최대 간격 길이
	int d = 0;
	int ans = 0;

	while (left <= right) {
		//기준
		int mid = (left + right) / 2;
		int start = houses[0];
		int cnt = 1;
		
		for (int i = 1; i < N; i++) {
			d = houses[i] - start;
			if (mid <= d) {//기준 간격보다 크거나 같다면 공유기 설치가 가능하다.
				++cnt;
				start = houses[i];
			}
		}

		if (cnt >= C) {
			//공유기의 수를 줄이자 -> 간격 넓히기
			ans = mid;
			left = mid + 1;
		}
		else {
			//공유기가 더 설치되어야 한다. -> 간격 줄이기
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}