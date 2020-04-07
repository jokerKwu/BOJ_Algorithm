#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
int N, K;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	int tmp = K;
	int num = 0;
	for (int i = 0; i < 9; i++) {
		ll tmp_value = (pow(10, i)*9)*(i+1);	//각 자리수마다 총 필요한 자리수를 계산
		if (tmp <= tmp_value) {
			//몇번째 숫자인지 체크
			int value = ceil((double)tmp / (double)(i + 1));
			num += value;
			string str_num = to_string(num);	
			if (num <= N) {
				int index = tmp % (i + 1);
				index +=i;
				cout << str_num[index%(i+1)] << '\n';
				break;
			}
			else {	// 범위보다 숫자가 초과하면 -1을 출력한다.
				cout << -1 << '\n';
				break;
			}
		}
		else {
			tmp -= tmp_value;		  
			num += (pow(10, i) * 9); //각 자리수마다 숫자 개수를 계속 더한다
		}
	}
	return 0;
}