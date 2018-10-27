#include<iostream>
using namespace std;
int ans, arr[6] = { 500,100,50,10,5,1 };
int calc(int value) {
	for (int i = 0; i < 6; i++) {
		if (value / arr[i] != 0) {
			if (value%arr[i] == 0)
				return value / arr[i];
			else
				return (value / arr[i]) + calc(value%arr[i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	ans = calc(1000-num);
	cout << ans << '\n';

	return 0;
}