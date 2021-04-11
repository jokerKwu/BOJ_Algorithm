#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	
	stack<char> stk;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ')') {
			if (stk.empty()) cnt++;
			else {
				while (!stk.empty()) {
					char ch = stk.top();
					stk.pop();
					if (ch == '(') break;
				}
			}
		}
		else if (str[i] == '(') {
			stk.push(str[i]);
		}
	}
	while (!stk.empty()) {
		stk.pop();
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}