#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e, f, c;
	cin >> e >> f >> c;
	int temp = e + f;
	int cnt = 0;
	while ((temp /c) != 0) {
		cnt += temp / c;
		temp = (temp / c) + (temp%c);
	}
	cout << cnt << '\n';
	return 0;
}