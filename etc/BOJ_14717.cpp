#include<iostream>
using namespace std;
bool visited[11];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(3);
	int a, b;
	int res = 0;
	cin >> a >> b;
	int ansMod = (a + b) % 10;
	if (a == b) {
		int res =(10 - a);
		double ans = ((double)res / (double)153);
		cout << (1-ans) << '\n';
	}
	else {
		visited[a] = true; visited[b] = true;
		for (int k = 0; k < ansMod; k++) {	//°®°í ÀÖ´Â ²ý
			for (int i = 1; i <= 10; i++) {
				for (int j = 1; j <= 10; j++) {
					int mod = (i + j) % 10;
					if (k == mod&&i!=j) {
						if ((visited[i] == false&&visited[j]==true)||(visited[i]==true&&visited[j]==false)) {
							res += 1;
						}
						else if(visited[i]==false&&visited[j]==false){
							res +=2;
						}
					}
				}
			}
		}
		cout << res << '\n';
		double ans = ((double)res / (double)153);
		cout << ans << '\n';
	}
}