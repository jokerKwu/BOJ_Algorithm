#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	//ansSize : 초콜릿 최소크기 splitCnt : 초콜릿 쪼개는 개수
	//cnt : 입력받은 k에 1의 개수 temp : 초콜릿 최소크기 임시저장 변수 
	//cSize : 입력받은 k 임시저장 변수 oneCnt : 1의 개수 카운트하는 변수
	int ansSize = 1, splitCnt = 0, cnt = 0,temp=0,cSize=0,oneCnt=0;
	
	while (ansSize < k) {//초콜릿 최소 크기 구하기
		int i = 1;
		ansSize <<= i;
	}
	cSize = k; temp = ansSize;
	for (; k != 0; cnt++) {//1의 개수 세기
		k &= (k - 1);
	}
	//비트연산
	while (cnt!=oneCnt) {
		if ((cSize&temp)!= 0)
			oneCnt++;
		splitCnt++;
		temp >>= 1;
	}
	cout << ansSize <<' '<<splitCnt-1<< '\n';
	return 0;
}