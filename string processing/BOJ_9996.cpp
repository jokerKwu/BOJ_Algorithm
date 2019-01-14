#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string pattern, front, back;
	bool flag = true;
	cin >> pattern;
	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == '*') {
			flag = false;
			continue;
		}
		if (flag == true) {
			front += pattern[i];
		}
		else {
			back += pattern[i];
		}
	}
	int frontSize = front.length();
	int backSize = back.length();
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		//실패한이유 패턴보다 입력받은 파일이름이 길이가 작은경우 예외 처리 해주어야된다.
		if (word.length() >= front.length() + back.length()) {
			if ((front == word.substr(0, frontSize)) && (back == word.substr(word.length() - back.length(), backSize))) {
				cout << "DA" << '\n';
			}
			else {
				cout << "NE" << '\n';
			}
		}
		else {
			cout << "NE" << '\n';
		}
	}
	return 0;
}