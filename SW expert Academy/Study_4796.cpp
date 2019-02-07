#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		int n,ans=0;
		cin >> n;
		vector<ll>v;
		queue<int>q;	// a <b 1 // a>b 2
		for (int i = 0; i < n; i++) {
			ll num;
			cin >> num;
			v.push_back(num);
		}
		int leftCnt = 0, rightCnt = 0;
		//이전 값과 비교해서 부등호 값을 큐에 넣었습니다. <는 1로 >는 2로  
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] < v[i])
				q.push(1);
			else if (v[i - 1] > v[i])
				q.push(2);
		}
		int prevD = q.front();	// 끝나는 지점을 확인하기위해 먼저 하나 꺼냅니다.
		if (prevD == 1) rightCnt++;
		else leftCnt++;
		q.pop();
		while (!q.empty()) {
			int curD = q.front();
			q.pop();
			if (prevD == 2 && curD == 1) {//다시 우뚝 선 산을 찾아야되는 경우라면 계산하고 카운트를 초기화해준다.
				ans += leftCnt * rightCnt;
				leftCnt = 0;
				rightCnt = 1;
			}
			else {
				if (curD == 1) rightCnt++;
				else leftCnt++;
			}
			prevD = curD;
		}
		ans += leftCnt * rightCnt;	//그냥 끝나는 경우도 있으므로 카운트했던 값들을 계산해서 결과값에 더해준다.
		cout <<'#'<<tc<<' '<< ans << '\n';
	}
	return 0;
}