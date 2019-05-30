#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 100001
bool visited[MAX];
int board[MAX],check[MAX],start_node[MAX];
int N;
int dfs(int cur,int cnt,int start) {
	if (check[cur] != 0) {
		if (start != start_node[cur])
			return 0;
		return cnt - check[cur];
	}
	check[cur] = cnt;
	start_node[cur] = start;
	return dfs(board[cur], cnt + 1, start);
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		cin >> N;
		int ans = 0;
		memset(board, 0, sizeof(board));
		memset(check, 0, sizeof(check));
		memset(start_node, 0, sizeof(start_node));
		for (int i = 1; i <= N; i++) {
			int num;
			cin >> num;
			board[i] = num;
		}
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {
				ans += dfs(i, 1, i);
			}
		}
		cout << N-ans << '\n';
	}
	return 0;
}