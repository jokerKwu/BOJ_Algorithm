#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1002
/*
7 6
11
*/
int board[MAX][MAX];
pair<int, int> pos;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N, K;
	cin >> M >> N;
	cin >> K;
	int sx = 1, sy = N;
	int number = 1;

	while (board[sy][sx] == 0) {
		//위로 올리고
		while (board[sy][sx] == 0 && sy != 0) {
			if (number == K) {
				pos.first = sx;
				pos.second = sy;
			}
			board[sy--][sx] = number++;
		}
		sx += 1, sy += 1;
		//오른쪽으로 가고
		while (board[sy][sx] == 0 && sx != M + 1) {
			if (number == K) {
				pos.first = sx;
				pos.second = sy;
			}
			board[sy][sx++] = number++;
		}
		sx -= 1, sy += 1;
		//아래로 가고
		while (board[sy][sx] == 0 && sy != N + 1) {
			if (number == K) {
				pos.first = sx;
				pos.second = sy;
			}
			board[sy++][sx] = number++;
		}
		sx -= 1, sy -= 1;
		//왼쪽으로 가고
		while (board[sy][sx] == 0 && sx != 0) {
			if (number == K) {
				pos.first = sx;
				pos.second = sy;
			}
			board[sy][sx--] = number++;
		}
		sx += 1, sy -= 1;
	}
	if (pos.first == 0 && pos.second == 0) {
		cout << 0 << '\n';
	}
	else {
		cout << pos.first << ' ' << (N - pos.second)+1 << '\n';
	}

	return 0;
}