#include<iostream>
using namespace std;
int arr[9] = { 100,100,200,200,300,300,400,400,500 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flag[2] = {false,false }; ///  hacker, draw
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		sum += n;
		if (arr[i] < n)flag[0] = true;
		else if (arr[i] == n) flag[1] = true;
	}
	if (sum < 100 && !flag[0] && !flag[1]) cout << "none\n";
	else if (flag[0]) cout << "hacker\n";
	else if (flag[1]) cout << "draw\n";
	return 0;
}