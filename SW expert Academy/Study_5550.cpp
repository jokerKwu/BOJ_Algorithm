#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#define MAX 501
#define INF 98765432
using namespace std;
int res;
int flogs[MAX];
int numCalc(char ch) {
	if (ch == 'c') return 0;
	else if (ch == 'r') return 1;
	else if (ch == 'o') return 2;
	else if (ch == 'a') return 3;
	else if (ch == 'k') return 4;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1;res!=-1, test_case <= T; ++test_case)
	{
		memset(flogs, 0, sizeof(flogs));
		string str;
		res = 0;
		cin >> str;
		for (int i = 0;i < str.length(); i++) {
			int charNum = numCalc(str[i]);
			int cnt = 0;
			for(int idx=0;idx<MAX;idx++){
				int& ret = flogs[idx];
				if(charNum==0&&ret==0){
					ret |= (1 << charNum);
					cnt++;
					res = max(res, cnt);
					break;
				}
				else if (charNum ==0  && ret!=31) {
					cnt++;
				}
				else if (charNum == 0 && ret == 31) {
					cnt = 0;
					continue;
				}
				else if (charNum!=0&&((ret&(1 << charNum)) == 0)) {//현재 그자리가 비어있는지 체크
					if (ret == ((1 << charNum) - 1)) {//이전글자가 꽉차있는지 체크
						ret |= (1 << charNum);
						break;
					}
					else {//안채워져있는데 그자리가 비어있다면 이상한거이므로 
						res = INF;
						break;
					}
				}
				else {//현재 그자리가 비어있지 않다면
					continue;
				}
			}
			if (res == INF) {
				res = -1;
				break;
			}
		}
		for (int i = 0; i < MAX; i++) {// 제대로 꽉차게 들어갔는지
			if (flogs[i] != 0 && flogs[i] != 31) {
				res = -1;
				break;
			}
		}
		cout << "#" << test_case << ' ' << res << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
