#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int pay[4],cnt=0;
	pay[0] = 0;
	//트럭 수에 따른 비용 
	for (int i = 1; i <= 3; i++) {
		cin >> pay[i];
	}
	pii car[3];
	//각 트럭 도착시간 출발 시간
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		car[i].first = start;
		car[i].second = end;
	}
	int total = 0;
	//반복문을 통해서 시간을 측정
	for (int i = 1; i <= 100; i++) {
		//각 트럭에 출발시간과 도착시간이 일치 할 경우 카운트 해준다.
		if (car[0].first == i)
			cnt++;
		else if (car[0].second == i)
			cnt--;
		if (car[1].first == i)
			cnt++;
		else if (car[1].second == i)
			cnt--;
		if (car[2].first == i)
			cnt++;
		else if (car[2].second == i)
			cnt--;
		//현재 트럭에 수에 따른 비용을 더해준다.
		total += pay[cnt] * cnt;
	}
	cout << total<<'\n';
	return 0;
}