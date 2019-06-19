#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, L;
int sig_sum(int len) {
	return ((len - 1)*len) / 2;
}
void res_print(int start,int len) {
	for (int i = start; i < start + len; i++) {
		cout << i << ' ';
	}cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	
	for (int i = L; i <= 100; i++) {
		if ((N - sig_sum(i)) / i >= 0 && (N - sig_sum(i)) % i == 0) {
			int start = (N - sig_sum(i)) / i;
			res_print(start, i);
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}