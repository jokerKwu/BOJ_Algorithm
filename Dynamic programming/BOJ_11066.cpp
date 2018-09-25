#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 501
int dp[MAX][MAX];
int arr[MAX],sum[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			arr[i] = num;
			sum[i] =sum[i-1]+num;
		}
		for (int i = 1; i < n; i++) {		//챕터 길이
			for (int x = 1; x+i <= n; x++) {//시작 챕터
				int y = x + i;				//끝나는 챕터 설정
				dp[x][y] = 987654321;		//초기값으로 INF값 설정
				for (int k = x; k < y; k++) {// 나누는 챕터
					dp[x][y] = min(dp[x][y], dp[x][k] + dp[k+1][y]+sum[y]-sum[x-1]);
				}
				cout << x<<' '<<y<<' '<<dp[x][y] << '\n';
			}
		}
		cout<<dp[1][n]<<'\n';
	}
	return 0;
}