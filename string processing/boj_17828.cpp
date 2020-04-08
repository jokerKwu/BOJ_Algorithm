#include<iostream>
#include<string>
using namespace std;
int N, X;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> X;
	string str = "";
	if (N > X||(26*N)<X) {
		cout << "!" << '\n';
	}
	else {
		int tmp = X - N;
		int value = (tmp / 25);
		int mod = (tmp%25);
		for (int i = 0; i < N; i++) {
			str += 'A';
		}
		int index = 0;
		if (value > 0) {
			for (int i = N - 1; i >= N - value; i--) {
				str[i] = 'Z';
				index = i;
			}
			if (index >= 1)
				str[index - 1] += mod;
			else if (index == 0)
				str[index] += mod;
				
		}else
			str[index] += mod;
		for (int i = 0; i < N; i++) {
			cout << str[i];
		}cout << '\n';
	}
	return 0;
}