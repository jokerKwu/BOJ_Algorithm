#include<iostream>
#include<cstring>
#include<cstdlib>

#define MAX 101
#define NEVER -1
#define USED 200
using namespace std;
int main() {
	int n;
	char **str = new char*[MAX];
	int arr[MAX][26];
	int groupWordCnt = 0;
	cin >> n;
		for (int i = 0; i < MAX; ++i) {
			str[i] = new char[MAX];
			memset(str[i], 0, sizeof(char)*MAX);	//초기화 작업
		}
		for (int i = 0; i < n; i++) {
			cin >> str[i];						//단어 입력받고
			for (int j = 0; j < 26; j++) {	//체크할 변수 초기화
				arr[i][j] = NEVER;
			}
		}
		for (int i = 0; i < n; i++) { //탐색 시작
			bool pass = true;
			for (int j = 0; j < strlen(str[i]); j++) {
				if (arr[i][(str[i][j] - 97)] == NEVER) {	//문자를 사++용을 안했다면 Used로 표시
					arr[i][(str[i][j] - 97)] = USED;
				}
				else if (arr[i][(str[i][j] - 97)] == USED) {	//사용을 했다면
					if (str[i][j] != str[i][j - 1]) {//이전 단어랑 다르다면 브레이크
						pass = false;
						break;
					}
				}
			}
			if (pass) {
				groupWordCnt++;
			}
		}
		cout << groupWordCnt << endl;
		for (int i = 0; i < MAX; ++i) {
			delete[] str[i];
		}
	return 0;
}