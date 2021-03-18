/*
5
1 4
4 3 3 2 1
5 2 4 3 2 1
4 4 3 3 1
4 3 2 1 1
4 2 3 2 1
4 4 3 2 1
3 4 3 2
5 4 4 2 3 1
5 4 2 4 1 3


A
B
B
A
D

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1002
int N;
int board[MAX][2][5];

char gamePlay(int round) {
	if (board[round][0][4] > board[round][1][4]) {
		//A가 이긴다.
		return 'A';
	}
	else if (board[round][0][4] == board[round][1][4]) {
		if (board[round][0][3] > board[round][1][3]) {
			//A가 이긴다.
			return 'A';
		}
		else if (board[round][0][3] == board[round][1][3]) {
			if (board[round][0][2] > board[round][1][2]) {
				//A가 이긴다.
				return 'A';
			}
			else if (board[round][0][2] == board[round][1][2]) {
				if (board[round][0][1] > board[round][1][1]) {
					//A가 이긴다.
					return 'A';
				}
				else if (board[round][0][1] == board[round][1][1]) {
					return 'D';
				}
				else {
					//B가 이긴다.
					return 'B';
				}
			}
			else {
				//B가 이긴다.
				return 'B';
			}
		}
		else {
			//B가 이긴다.
			return 'B';
		}
	}
	else {
		//B가 이긴다.
		return 'B';
	}
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 2;j++) {
			int n;
			cin >> n;
			for (int k = 0;k < n;k++) {
				int num;
				cin >> num;
				board[i][j][num]++;
			}
		}
		cout << gamePlay(i) << '\n';
	}
	

	return 0;
}