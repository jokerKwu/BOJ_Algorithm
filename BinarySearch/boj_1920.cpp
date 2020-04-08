#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
typedef long long ll;
vector<ll> arr;

int binarySearch(ll findNum) {
	int left = 0, right = arr.size()-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == findNum) {
			return 1;
		}
		else if (arr[mid] > findNum) {
			right = mid-1;	//-1 하고 안하고 시간초과
		}
		else {
			left = mid + 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		ll num;
		cin >> num;
		cout<<binarySearch(num)<<'\n';
		//cout << binary_search(arr.begin(), arr.end(), num)<<'\n';	//라이브러리 함수 사용
	}

	return 0;
}