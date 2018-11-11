#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, b;
	cin >> r >> b;
	for (int i = 1; i < 5000; i++) {
		for (int j = 1; j < 5000; j++) {
			int res = (i * 2) + (j * 2 - 4);		//레드 개수 구하기
			if (res > r) {
				break;
			}
			else if (res == r) {	//레드 개수가 res 개수와 같다면
				int tmp = (i - 2)*(j - 2);		//브라운 개수 구하기
				if (tmp == b) {
					if (i > j) {		// 큰 수가 L이 되도록 구현
						cout << i << ' ' << j << '\n';
						return 0;
					}
					else {
						cout << j << ' ' << i << '\n';
						return 0;
					}
				}
			}
		}
	}

	return 0;
}