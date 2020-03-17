#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int cnt = 0; cnt < N; cnt++) {
		string str;
		cin >> str;
		int answer = 0;
		int len = str.length();
		int i = 0, j = len - 1;
		while (i < j) {
			if (str[i] == str[j]) {
				i++; j--;
			}
			else if (str[i + 1] == str[j] || str[i] == str[j - 1]) {
				//오른쪽 제거
				if (str[i + 1] == str[j]) {
					int ti = i + 1, tj = j;
					answer = 1;
					while (ti < tj) {
						if (str[ti] == str[tj]) {
							ti++; tj--;
						}
						else {
							answer = 2;
							break;
						}
					}
				}
				//왼쪽 제거
				if (answer != 1 && str[i] == str[j - 1]) {
					int ti = i, tj = j - 1;
					answer = 1;
					while (ti < tj) {
						if (str[ti] == str[tj]) {
							ti++; tj--;
						}
						else {
							answer = 2;
							break;
						}
					}
				}
				break;
			}
			else {
				answer = 2;
				break;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}