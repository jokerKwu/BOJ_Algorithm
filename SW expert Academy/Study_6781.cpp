#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef pair<int, int>pii; //컬러, 번호
int function1(int card[3][10]) {
	int setCnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 7; j++) {//연속된 숫자 체크
			if ((card[i][j] >= 1) && (card[i][j + 1] >= 1) && (card[i][j + 2] >= 1)) {
				card[i][j]--;
				card[i][j + 1]--;
				card[i][j + 2]--;
				setCnt++;
				j -= 1;
			}
		}
		for (int j = 1; j <= 9; j++) {//똑같은숫자 체크
			if (card[i][j] >= 3) {
				card[i][j] -= 3; setCnt++;
				j -= 1;
			}
		}
	}
	return setCnt;
}
int function2(int card[3][10]) {
	int setCnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 9; j++) {//똑같은숫자 체크
			if (card[i][j] >= 3) {
				card[i][j] -= 3; setCnt++;
				j -= 1;
			}
		}
		for (int j = 1; j <= 7; j++) {//연속된 숫자 체크
			if ((card[i][j] >= 1) && (card[i][j + 1] >= 1) && (card[i][j + 2] >= 1)) {
				card[i][j]--;
				card[i][j + 1]--;
				card[i][j + 2]--;
				setCnt++;
				j -= 1;
			}
		}
	}
	return setCnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		int card[3][10];	//컬러 번호
		int setCnt = 0,res=0;
		memset(card, 0, sizeof(card));
		string num, color;
		cin >> num >> color;
		for (int i = 0; i < 9; i++) {
			if (color[i] == 'R') card[0][num[i] - '0']++;
			else if (color[i] == 'G') card[1][num[i] - '0']++;
			else card[2][num[i] - '0']++;
		}
		res = max(function1(card), function2(card));
		if (res == 3) {
			cout << '#' << tc << " Win\n";
		}
		else {
			cout << '#' << tc << " Continue\n";
		}
	}

	return 0;
}