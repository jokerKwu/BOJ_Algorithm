#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX 12
int N;
int inigs[52][MAX];
int orders[MAX];
bool visited[MAX];
int answer;
int playGame() {
	int score = 0;
	int index = 0;
	bool doru[3];
	//이닝 
	
	for (int i = 1; i <= N; i++) {
		int out = 0;
		memset(doru, false, sizeof(doru));
		while (out != 3) {
			if (index == 9) index = 0;
			int value = inigs[i][orders[index]];
			if (value == 0) {
				out++;
			}
			else if (value == 1) {
				if (doru[2]) {
					score++;
					doru[2] = false;
				}
				if (doru[1]) {
					doru[1] = false;
					doru[2] = true;
				}
				if (doru[0]) {
					doru[0] = false;
					doru[1] = true;
				}
				doru[0] = true;
			}
			else if (value == 2) {
				if (doru[2]) {
					score++;
					doru[2] = false;
				}
				if (doru[1]) {
					score++;
					doru[1] = false;
				}
				if (doru[0]) {
					doru[0] = false;
					doru[2] = true;
				}
				doru[1] = true;
			}
			else if (value == 3) {
				if (doru[2]) {
					doru[2] = false;
					score++;
				}
				if (doru[1]) {
					doru[1] = false;
					score++;
				}
				if (doru[0]) {
					doru[0] = false;
					score++;
				}
				doru[2] = true;
			}
			else if (value == 4) {
				for(int j=0;j<3;j++)
					if (doru[j]) {
						score++;
						doru[j] = false;
					}
				score++;
			}
			index++;
		}
	}
	return score;
}
void dfs(int cnt) {
	if (cnt == 3) {//3번타자까지 정해졌다면 4번타는 첫번째 선수를 지정
		orders[cnt] = 1;
		visited[1] = true;
		dfs(cnt + 1);
		visited[1] = false;
	}
	else if (cnt == 9) {//9번타자까지 정해졌다면 게임을 진행한다.
		int tmp=playGame();
		answer = max(tmp, answer);
		return;
	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (!visited[i]) {
				orders[cnt] = i;
				visited[i] = true;
				dfs(cnt + 1);
				visited[i] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> inigs[i][j];
		}
	}
	//순서를 정하고 (dfs로)
	dfs(0);
	cout << answer << '\n';
	return 0;
}