#include <iostream>
using namespace std;
#define MAX 1000004
typedef long long ll;
int D[MAX];
int main(void) {
	int T;
	cin >> T;
	for(int tc=1;tc<=T;tc++){
		ll ans = 0;
		int N;
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> D[i];
		int tmpmx = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (tmpmx > D[i])
				ans += tmpmx - D[i];
			else
				tmpmx = D[i];
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}

