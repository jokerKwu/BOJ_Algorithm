#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define MAX 3000
bool dp[MAX][MAX];
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	int len = str.length();
	/*
	i는 길이
	길이 1과 2를 초기화시킨다.
	arr변수는 팰린드롬이 시작하는 인덱스를 저장
	*/
	//길이 1짜리 초기화
	for (int i = 0; i < len; i++) {
		dp[i][i] = true;
	}	
	//길이 2짜리 초기화
	for (int i = 0; i < len-1; i++) {
		if (str[i] == str[i + 1]) {
			dp[i][i+1] = true;
		}
	}
	for (int i = 2; i <= len-1; i++) {//길이 3부터 시작해서 최대 문자 길이까지
		for (int j = 0; j < len - i; j++) {//해당 길이만큼 글자를 탐색
			if (str[j] == str[j + i] && dp[j + 1][j + i - 1]) {//안에 문자가 팰린드롬이고 앞뒤가 같으면 팰린드롬
				dp[j][j + i] = true;
			}
		}
	}
	//dp를 이용하여 i번째 인덱스까지 문자열의 분할 개수 최소값을 구하도록 한다.
	for (int i = 0; i < len; i++) {//문자 끝인덱스
		arr[i] = i+1;	//i번째 인덱스에 초기화 작업 문자 개수 만큼
		for (int j = 0; j <= i; j++) {//문자 시작인덱스
			if (dp[j][i]) {//팰린드롬이라면
				if (arr[i] > arr[j-1] + 1) {//팰린드롬이므로 시작위치 이전 arr값이랑 +1해서 더 작다면 그값으로 초기화
					arr[i] = arr[j-1] + 1;
				}
			}
		}
	}
	cout << arr[len-1] << '\n';
	return 0;
}