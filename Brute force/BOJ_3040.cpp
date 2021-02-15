#include<iostream>
using namespace std;
bool visit[10];
int arr[10];
void backtracking(int idx,int value,int cnt) {
	if (idx == 10) return;
	if (value == 100&&cnt == 7) {
		for (int i = 0; i < 10; i++) {
			if (visit[i] == true) {
				cout << arr[i] << '\n';
			}
		}
		return;
	}
	visit[idx] = true;
	backtracking(idx + 1, value + arr[idx],cnt+1);
	visit[idx] = false;

	backtracking(idx + 1, value,cnt );
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	backtracking(0, 0,0);
	
	return 0;
}