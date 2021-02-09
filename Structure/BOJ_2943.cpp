#include<iostream>
#include<stack>
using namespace std;
#define MAX 500002
int N;
typedef pair<int, int> pii;
int answer[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<pii> stk;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int num;
		cin >> num;
		if (stk.empty()) {
			answer[i] = 0;
		}
		else {
			while (!stk.empty()&&stk.top().first<num) {
				stk.pop();
			}
			if (stk.empty()) answer[i] = 0;
			else answer[i] = stk.top().second;
		}
		//스택에 넣는다.
		stk.push({ num,i });
	}
	for (int i = 1;i <= N;i++) cout << answer[i] << ' ';
	cout << '\n';
	return 0;
}