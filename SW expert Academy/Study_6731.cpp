#include<iostream>
#include<string.h>
using namespace std;
#define MAX 1001
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		int n,res=0,cols[MAX],rows[MAX];
		char board[MAX][MAX];
		cin >> n;
		memset(board,NULL, sizeof(board));
		memset(cols, 0, sizeof(cols));
		memset(rows, 0, sizeof(rows));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'B') {
					cols[i]++;
					rows[j]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp = cols[i] + rows[j];
				if (board[i][j] == 'B' && (tmp - 1) % 2 != 0) res++;
				else if (board[i][j] == 'W'&&tmp % 2 != 0) res++;
			}
		}
		cout << '#' << tc << ' ' <<res<< '\n';
	}
	return 0;
}