#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int A, B, C, D, E;	//시작 온도, 목표 온도, 얼어 있는 고기 1도 데우는데 C , 얼어 있는 고기 해동하는 데 걸리는 시간 D, 얼어 있지 않은 고기를 1도 데우는데 E
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C >> D >> E;
	
	int time = 0;
	
	while (A != B) {
		if (A < 0) {
			time += C;
			A += 1;
		}
		else if (A == 0) {
			time += (D+E);
			A += 1;
		}
		else {
			time += E;
			A += 1;
		}
	}
	cout << time << '\n';
	
	return 0;
}