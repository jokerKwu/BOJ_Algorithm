#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
#define MAX 1000000
int currentCh = 100,breackCnt,targetCh,min;
bool breakCh[10];
bool checkFunc(int num) {
	while (num / 10 != 0) {
		if (breakCh[num % 10] == true) {
			return false;
		}
		num /= 10;
	}
	if (breakCh[num % 10] == true)
		return false;
	else
		return true;
}
int cmdCountFunc(int num) {
	int cnt = 1;
	while ((num / 10) != 0) {
		cnt++;
		num /= 10;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> targetCh >> breackCnt;
	for (int i = 0; i < breackCnt; i++)
	{
		int n;
		cin >> n;
		breakCh[n] = true;
	}
	min = abs(targetCh - currentCh);//+ - 로 이동시 횟수
	for (int i = 0; i <= MAX; i++) {
		if (checkFunc(i)) {//고장난 버튼들로 만들어진 숫자인지 체크하는 함수
			int currentCmd = cmdCountFunc(i);//현재 i가 몇번 눌렀는지 카운팅함수
			currentCmd += abs(targetCh - i);
			if (min > currentCmd)
				min = currentCmd;
		}
	}
	cout << min << '\n';
	return 0;
}