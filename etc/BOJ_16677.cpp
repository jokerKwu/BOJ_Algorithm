#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string jamStr;
	cin >> jamStr;
	int n;
	cin >> n;
	vector<pair<string, double>>v;
	for (int i = 0; i < n; i++) {
		string w;
		int g;
		cin >> w >> g;
		int idx = 0, cnt = 0, jamIdx = 0;
		double value=0;
		if (jamStr.length() <= w.length()) {
			for (int j = idx; jamIdx != jamStr.length() && j < w.length(); j++) {
				if (jamStr[jamIdx] == w[j] && jamIdx != jamStr.length()) {
					idx = j + 1;
					jamIdx++;
					if (jamIdx == jamStr.length()) {
						cnt += (w.length() - 1) - j;
					}
				}
				else {
					cnt++;
				}
			}
		}
		if (jamIdx == jamStr.length()) {
			value = (double)g / (double)cnt;
			v.push_back(make_pair(w, value));
		}
		else {
			v.push_back(make_pair(w, 0));
		}
	}
	double res = 0;
	string resStr = "No Jam";
	for (int i = 0; i < v.size(); i++) {
		if (res < v[i].second) {
			res = v[i].second;
			resStr = v[i].first;
		}
	}
	cout << resStr << '\n';
	return 0;
}