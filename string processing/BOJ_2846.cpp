#include<iostream>
#include<string>
using namespace std;
#define MAX 8
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char num1[MAX], num2[MAX], tmp1[MAX], tmp2[MAX];
	cin >> num1 >> num2;
	for (int i = 0; i < sizeof(num1); i++) {
		if (num1[i] == '5') {
			tmp1[i] = '6';
		}
		else
			tmp1[i] = num1[i];
	}
	for (int i = 0; i < sizeof(num2); i++) {
		if (num2[i] == '5') {
			tmp2[i] = '6';
		}
		else
			tmp2[i] = num2[i];
	}
	int Max = atoi(tmp1) + atoi(tmp2);
	for (int i = 0; i < sizeof(num1); i++) {
		if (num1[i] == '6') {
			tmp1[i] = '5';
		}
		else
			tmp1[i] = num1[i];
	}
	for (int i = 0; i < sizeof(num2); i++) {
		if (num2[i] == '6') {
			tmp2[i] = '5';
		}
		else
			tmp2[i] = num2[i];
	}
	int Min = atoi(tmp1) + atoi(tmp2);
	cout << Min<< ' ' << Max << '\n';
	return 0;
}