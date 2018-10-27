#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 11
int arr[MAX],n,per[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];		//arr 은 큰 개수 저장 배열
		v.push_back(i);		//순열을 사용하기 위한 벡터 배열
	}
	queue<int>q;
	do{
		for (int i = 0; i < v.size(); i++) {
			int cnt = 0;
			for (int j = 0; j <i; j++) {	//현재 i번째 사람이 왼쪽에 자기보다 큰 사람이 몇명인지 체크하는 반복문
				if (v[j] > v[i]) {
					cnt++;
				}
			}
			if (arr[v[i]] == cnt)	//기억하고있는 사람 수와 일치하다면
				q.push(v[i]);
			else {
				while (!q.empty())
					q.pop();
				break;
			}
		}
		if (q.size() == n)
			break;
	} while (next_permutation(v.begin(),v.end()));

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		cout << num << ' ';
	}cout << '\n';
	return 0;
}