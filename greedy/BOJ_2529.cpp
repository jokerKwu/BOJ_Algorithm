#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>number;
vector<char>sign;
long long maxValue, minValue=9876543210;
int maxArr[11], minArr[11];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		sign.push_back(c);
	}
	for (int i = 0; i < 10; i++) {
		number.push_back(i);
	}
	do {
		bool flag = true;//이전 부등호 연산 체크변수
		for (int i = 1; i <= n; i++) {
			if (flag==true&&sign[i - 1] == '<') {// < 부등호인 경우
				if (number[i - 1] < number[i])
					flag = true;
				else {
					flag = false;
					break;
				}
			}
			else if(flag==true&&sign[i-1]=='>'){// > 부등호인 경우
				if (number[i - 1] > number[i])
					flag = true;
				else {
					flag = false;
					break;
				}
			}
			else {
				break;
			}
		}
		if (flag==true) {//연산에 정답일 경우
			long long tempValue = 0;
			for (int i = 0; i <= n; i++) {
				tempValue = tempValue * 10 + number[i];
			}
			if (maxValue <= tempValue) {
				maxValue = tempValue;
				for (int i = 0; i <= n; i++)
					maxArr[i] = number[i];
			}
			if (minValue >= tempValue) {
				minValue = tempValue;
				for (int i = 0; i <= n; i++)
					minArr[i] = number[i];
			}
		}
	} while (next_permutation(number.begin(), number.end()));
	for (int i = 0; i <= n; i++) {
		cout << maxArr[i];
	}cout << '\n';
	for (int i = 0; i <= n; i++) {
		cout << minArr[i];
	}cout << '\n';
	return 0;
}