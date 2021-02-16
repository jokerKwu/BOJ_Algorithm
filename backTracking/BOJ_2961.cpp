#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
typedef long long ll;
typedef pair<ll,ll>pll;
vector<pll> arr;
bool visit[11];
ll answer=987543210;
void backtracking(int idx,int cnt) {
	if (idx == N ) {
		if (cnt == 0) return;
		ll aValue = 1;
		ll bValue = 0;
		for (int i = 0; i < N; i++) {
			if (visit[i] == true) {
				aValue *= arr[i].first;
				bValue += arr[i].second;
			}
		}
		answer = min(answer, abs(aValue - bValue));
		return;
	}
	//선택한다
	visit[idx] = true;
	backtracking(idx + 1,cnt + 1);
	visit[idx] = false;
	
	backtracking(idx + 1, cnt);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		pll tmp;
		cin >> tmp.first >> tmp.second;
		arr.push_back(tmp);
	}
	
	backtracking(0, 0);
	cout << answer << '\n';
	return 0;
}