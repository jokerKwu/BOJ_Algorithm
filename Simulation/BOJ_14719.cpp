#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 502
int N, M;
int arr[MAX];
int answer;
typedef pair<int, int> pii;	//인덱스, 값
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	pii start, end , mid ;
	for (int i = 0; i < M; i++) {
		if (arr[i] != 0) {
			start = { i,arr[i] };
			end = { -1,-1 };
			mid = { -1,-1 };
			int j = i + 1;
			while (j<M) {
				if (arr[j] >= start.second) {
					end = { j,arr[j] };
					break;
				}
				else {
					if (mid.second < arr[j]) {
						mid = { j, arr[j] };
					}
					j++;
				}
			}
			//끝을 찾았다면
			if (end.first != -1) {
				int minValue = min(start.second, end.second);
				for (int j = i + 1; j < end.first; j++) {
					answer += (minValue - arr[j]);
				}
				i = end.first-1;
			}
			//못찾아다면
			else if(mid.first!=-1){
				int minValue = min(start.second, mid.second);
				for (int j = i + 1; j < mid.first; j++) {
					answer += (minValue - arr[j]);
				}
				i = mid.first-1;
			}
		}
	}
	cout << answer << '\n';

	return 0;
}