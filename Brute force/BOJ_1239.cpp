#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int>v;
	int n,cnt=0,max=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	//순열 돌리기전 정렬
	sort(v.begin(), v.end());
	do {
		cnt = 0;
		vector<int>t;
		for (int i = 0; i < n; i++) {
			t.push_back(v[i]);
		}
		//배열 복사하기 
		for (int i = 0; i < n; i++) {
			t.push_back(v[i]);
		}
		for (int i = 0; i < n; i++) {//입력 받은 길이만큼 반복문
			int tmp = 0;
			for (int j = i; j < t.size(); j++) {//전체 배열 반복문
				tmp += t[j];
				if (tmp == 50) {//50 인 경우 카운팅
					cnt++;
					break;
				}
				else if (tmp > 50) {	//50이상이면 break
					break;
				}
			}
		}
		t.clear();
		if (max < cnt) {
			max = cnt;
		}
	} while (next_permutation(v.begin(), v.end()));//다음 순열 이동
	cout << max/2 << '\n';
	return 0;
}