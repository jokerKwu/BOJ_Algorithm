#include<iostream>
using namespace std;
long long a, b, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	long long diff = c - b;
	long long res = 0;
	if (diff <= 0) {
		cout << -1 << '\n';
	}
	else {
		res = a / diff;
		cout << res + 1 << '\n';
	}
	return 0;
}