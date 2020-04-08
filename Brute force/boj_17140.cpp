#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<string>
using namespace std;
#define MAX 106
int board[MAX][MAX];
int r, c, k,answer=-1;
int len_r, len_c;

typedef pair<int, int> pii; //수의 개수 , 수

bool cmp(pii &a, pii &b) {
	if (a.first > b.first)return false;
	else if (a.first == b.first) {
		if (a.second > b.second)return false;
		else return true;
	}
	else return true;
}

void solve(int type) {
	//print();
	set<int> tmp;
	vector<pii> v_arr;
	//모든 행에 대해서 정렬을 수행한다.
	if (type == 1) {
		for (int i = 1; i <= len_c; i++) {
			int arr[MAX];
			memset(arr, 0, sizeof(arr));

			//각 행에 대해서 값을 다 넣었고
			for (int j = 1; j <= len_c; j++) {
				if (board[i][j] != 0) {
					arr[board[i][j]]++;
					tmp.insert(board[i][j]);
				}
			}

			//정렬을 한다.
			set<int>::iterator iter;
			for (iter = tmp.begin(); iter != tmp.end(); iter++) {
				v_arr.push_back(make_pair(arr[*iter], *iter));
			}
			sort(v_arr.begin(), v_arr.end(),cmp);
			int index = 1;
			for (int j = 1; j <= len_c; j++) board[i][j] = 0;
			for (int j = 0; j < v_arr.size(); j++) {
				int num_cnt = v_arr[j].first;
				int num = v_arr[j].second;
				board[i][index++] = num;
				if (index > 100) break;
				board[i][index++] = num_cnt;
				if (index > 100)break;
			}
			len_r = max(len_r, index-1);
			//초기화
			tmp.clear();
			v_arr.clear();
		}
	}
	//모든 열에 대해서 정렬을 수행한다.
	else {
	
		for (int i = 1; i <= len_r; i++) {
			int arr[MAX];
			memset(arr, 0, sizeof(arr));
			
			for (int j = 1; j <= len_r; j++) {
				if (board[j][i] != 0) {
					arr[board[j][i]]++;
					tmp.insert(board[j][i]);
				}
			}

			//정렬을 한다.
			set<int>::iterator iter;
			for (iter = tmp.begin(); iter != tmp.end(); iter++) {
				v_arr.push_back(make_pair(arr[*iter], *iter));
			}
			sort(v_arr.begin(), v_arr.end(), cmp);
			int index = 1;
			for (int j = 1; j <= len_r; j++) board[j][i] = 0;
			for (int j = 0; j < v_arr.size(); j++) {
				int num_cnt = v_arr[j].first;
				int num = v_arr[j].second;
				board[index++][i] = num;
				if (index > 100) break;
				board[index++][i] = num_cnt;
				if (index > 100)break;
			}
			len_c = max(len_c, index - 1);
			//초기화
			tmp.clear();
			v_arr.clear();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c >> k;
	len_c = 3, len_r = 3;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
		}
	}
	for (int time = 0; time <= 100; time++) {
		if (board[r][c] == k) {
			answer = time;
			break;
		}
		//행의 개수 >= 열의 개수
		if (len_c >= len_r) {
			solve(1);
		}
		//행의 개수 < 열의 개수
		else {
			solve(2);
		}
	}
	cout << answer << '\n';

	return 0;
}