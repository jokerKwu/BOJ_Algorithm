#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>v;
	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	char str[3];
	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < 3; i++) {
		switch (str[i])
		{
		case 'A':
			cout << v[0] << ' ';
			break;
		case 'B':
			cout << v[1] << ' ';
			break;
		case 'C':
			cout << v[2] << ' ';
			break;
		}
	}cout << '\n';

	return 0;
}