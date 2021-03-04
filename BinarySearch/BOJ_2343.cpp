#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr;
typedef long long ll;
/*
9 3
1 2 3 4 5 6 7 8 9
*/
bool check(ll value) {
	int cnt = 1;
	ll sum = 0;
	cout << value << '\n';
	for (int i = 0;i < arr.size();i++) {
		if (arr[i] > value) return false;
		sum += arr[i];
		if (sum > value) {
			cnt++;
			sum =arr[i];
		}
	}
	if (M >= cnt) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	ll sum = 0;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		sum += num;
	}
	ll left = 0, right = sum;
	ll answer = 98765432230;
	while (left <= right) {
		ll mid = (left + right) / 2;	//�ִ밪
		if (check(mid) == true) {
			answer = min(mid, answer);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << answer << '\n';
	

	return 0;
}