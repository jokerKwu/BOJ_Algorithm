#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
using namespace std;
int ans=5;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<long long>s;	//숫자가 들어있는지 체크하기 위한 변수
	vector<long long>v;	
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		s.insert(num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (long long j = v[i]+1; j < v[i] + 5 && j <= 10e9; j++) {
			if (s.count(j) == 0)	//입력값이 들어있지않다면
				cnt++;
		}
		if (ans > cnt)
			ans = cnt;
	}
	cout << ans << '\n';
	return 0;
}