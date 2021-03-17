#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 1002
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string board;
	cin >> board;
	
	int cnt = 0;
	for (int i = 0;i < board.length();i++) {
		if (board[i] == 'Y') {
			cnt++;
			for (int j = i;j < board.length();j += (i+1)) {
				if (board[j] == 'Y') board[j] = 'N';
				else board[j] = 'Y';
			}
		}
	}
	for (int i = 0;i < board.length();i++) {
		if (board[i] == 'Y') {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << cnt << '\n';
	
	return 0;
}
