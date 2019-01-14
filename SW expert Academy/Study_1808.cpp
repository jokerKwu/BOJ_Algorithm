	#include<iostream>
	#include<queue>
	#include<set>
	#include<vector>
	#include<string.h>
	using namespace std;
	#define INF numeric_limits<int>::max()
	bool calcNum[10];
	vector<int>possibleNum;
	int n;
	typedef pair<long, long>pll;
	//전달받은 매개변수 num이 활성화된 버튼으로 이루어져 있다면 true 아니면 false
	bool check(int num) {
		while (num !=0) {
			if (calcNum[num % 10] == false)
				return false;
			else
				num /= 10;
		}
		return true;
	}
	//매개변수 자리수 확인하는 함수 == 숫자를 얻기 위해서 누른 버튼 횟수
	int countFunc(int num) {
		int res = 0;
		while (num != 0) {
			num /= 10;
			res++;
		}
		return res;
	}
	int bfs(int n) {
		priority_queue<pll>pq;		//숫자  , 버튼 누른 횟수
		set<int>s;					//방문했는지 체크하기 위한 변수
		int res = INF;
		for (int i = 0; i < possibleNum.size(); i++) {
			pq.push(make_pair(possibleNum[i],countFunc(possibleNum[i])));	//숫자, 숫자 버튼누른 횟수로 초기화
			s.insert(possibleNum[i]);	
		}
		while (!pq.empty()) {
			long long curNum = pq.top().first;		//들어있는 숫자 (약수)
			long long btnCnt = pq.top().second;	//버튼 누른 횟수
			long long divNum = n / curNum;			//나눈 몫 
			if (n%curNum == 0 && check(divNum)) {	//나눈 몫이 버튼으로 구할 수 있고 약수라면
				int value=0,curNumCnt = 0,divNumCnt=0;
				value = countFunc(divNum);			//나눈 몫 버튼 횟수를 체크
				if (res > value + btnCnt + 2)		//2를 더하는 이유는 +,= 버튼을 누른것이다.
					res = value + btnCnt + 2;		//최소값으로 업데이트
			}
			pq.pop();
			for (int i = 0; i < possibleNum.size(); i++) {// 약수들끼리 곱하는 구간
				long long nextNum = curNum * possibleNum[i];
				if (s.count(nextNum) == 0&&nextNum<=n) {//방문했는지 체크, 입력받은 숫자보다 작거나 같은지
					long long nextOperCnt = btnCnt + 1 + countFunc(possibleNum[i]);	//현재까지 누른 버튼횟수 + *버튼 + 곱할숫자 버튼횟수
					pq.push(make_pair(nextNum,nextOperCnt));
					s.insert(nextNum);
				}
			}
		
		}
		s.clear();
		if (res == INF) return -1;
		else return res;
	}
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int testCase;
		cin >> testCase;
		for(int tc=1;tc<=testCase;tc++){
			memset(calcNum, 0, sizeof(calcNum));
			possibleNum.clear();
			for (int i = 0; i < 10; i++) {
				cin >> calcNum[i];
			}
			cin >> n;
			if (check(n)) {//곱하기 연산이 필요없이 한방에
				cout <<"#"<<tc<<' '<<countFunc(n) + 1 << '\n';
			}
			else {
				for (int i = 1; i <= n/2; i++) {	//곱하기 연산을 사용하므로 반만 탐색
					if (n%i == 0 && check(i)) {		// i가 약수이고 버튼이 전부 활성화 되어있다면
						possibleNum.push_back(i);
					}
				}
				cout << "#" << tc << ' ' << bfs(n) << '\n';
			}
		}
		return 0;
	}