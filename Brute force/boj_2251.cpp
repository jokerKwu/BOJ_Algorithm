#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 202
using namespace std;
bool check[MAX][MAX][MAX];
set<int> answer;
int A, B, C;
void dfs(int a, int b, int c) {
	check[a][b][c] = true;
	int tmpA = a, tmpB = b, tmpC = c;
	//A->B
	//a 있는 걸 b에 넣는거지
	if (B - b > 0) {
		if ((B - b) > a) {
			tmpA = 0; tmpB = b + a; tmpC = c;
		}
		else {
			tmpA = a - (B - b); tmpB = B; tmpC = c;
		}
		if (!check[tmpA][tmpB][tmpC]) {
			check[tmpA][tmpB][tmpC] = true;
			if (tmpA == 0) {
				answer.insert(tmpC);
			}
			dfs(tmpA, tmpB, tmpC);
		}
	}
	//A->C
	if (C - c > 0) {
		if ((C - c) > a) {
			tmpA = 0; tmpB = b; tmpC = c + a;
		}
		else {
			tmpA = a - (C - c); tmpB = b; tmpC = C;
		}
		if (!check[tmpA][tmpB][tmpC]) {
			check[tmpA][tmpB][tmpC] = true;
			if (tmpA == 0) {
				answer.insert(tmpC);
			}
			dfs(tmpA, tmpB, tmpC);
		}
	}
	//B->A
	if (A - a > 0) {
		if ((A - a) > b) {
			tmpA = a + b; tmpB = 0; tmpC = c;
		}
		else {
			tmpA = A; tmpB = b - (A - a); tmpC = c;
		}
		if (!check[tmpA][tmpB][tmpC]) {
			check[tmpA][tmpB][tmpC] = true;
			if (tmpA == 0) {
				answer.insert(tmpC);
			}
			dfs(tmpA, tmpB, tmpC);
		}
	}
	//B->C
	if (C - c > 0) {
		if ((C - c) > b) {
			tmpA = a; tmpB = 0; tmpC = c + b;
		}
		else {
			tmpA = a; tmpB = b - (C - c); tmpC = C;
		}
		if (!check[tmpA][tmpB][tmpC]) {
			check[tmpA][tmpB][tmpC] = true;
			if (tmpA == 0) {
				answer.insert(tmpC);
			}
			dfs(tmpA, tmpB, tmpC);
		}
	}
	//C->A
	if (A - a > 0) {
		if ((A - a) > c) {
			tmpA = a + c; tmpB = b; tmpC = 0;
		}
		else {
			tmpA = A; tmpB = b; tmpC = c - (A - a);
		}
		if (!check[tmpA][tmpB][tmpC]) {
			check[tmpA][tmpB][tmpC] = true;
			if (tmpA == 0) {
				answer.insert(tmpC);
			}
			dfs(tmpA, tmpB, tmpC);
		}
	}
	//C->B
	if (B - b > 0) {
		if ((B - b) > c) {
			tmpA = a; tmpB = b + c; tmpC = 0;
		}
		else {
			tmpA = a; tmpB = B; tmpC = c - (B - b);
		}
		if (!check[tmpA][tmpB][tmpC]) {
			check[tmpA][tmpB][tmpC] = true;
			if (tmpA == 0) {
				answer.insert(tmpC);
			}
			dfs(tmpA, tmpB, tmpC);
		}
	}
}

int main() {

	cin >> A >> B >> C;

	dfs(0, 0, C);
	answer.insert(C);
	for (auto it = answer.begin(); it != answer.end(); it++) cout << *it << ' ';


	return 0;
}