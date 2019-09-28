#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int N, F;
#define MAX 200022
int parent[MAX];
int c[MAX];
int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}
int Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
		c[x] += c[y];
		c[y] = 1;
	}
	return c[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N ;
	for (int i = 0; i < N; i++) {
		cin >> F;
		map<string, int> m;
		int index = 0;
		for (int i = 1; i <= F * 2; i++) {
			parent[i] = i;
			c[i] = 1;
		}
		for (int j = 0; j < F; j++) {

			string f1, f2;
			cin >> f1 >> f2;
			if (m.count(f1)==0) {
				m[f1] = ++index;
			}
			if (m.count(f2) == 0) {
				m[f2] = ++index;
			}
			cout << Union(m[f1], m[f2]) << '\n';
		}
	}

	return 0;
}