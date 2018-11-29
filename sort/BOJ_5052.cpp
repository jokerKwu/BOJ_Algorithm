#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		bool ok = false;
		vector<string>v;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n-1; i++) {
			string cmp = v[i];
			string tmp = v[i+1];
			if ((tmp.find(cmp) != string::npos)) {
					ok = true;
					break;
			}
		}
		if (ok)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
	return 0;
}