#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
char gears[5][8];
int K;
int ontime_idx[5];		//초기 12시 0을 가리킨다.
bool cmp_check[4];

char getValue(int gear_num,int location) {//톱니바퀴 왼쪽 0, 오른쪽 값 반환1
	if (location == 0) {//0 왼쪽+6
		int next_idx = ontime_idx[gear_num] + 6;
		if (next_idx > 7) {
			return gears[gear_num][next_idx - 8];
		}
		else {
			return gears[gear_num][next_idx];
		}
	}
	else {//1	오른쪽	+2
		int next_idx = ontime_idx[gear_num] + 2;
		if (next_idx > 7) {
			return gears[gear_num][next_idx - 8];
		}
		else {
			return gears[gear_num][next_idx];
		}
	}
}
//톱니바퀴 비교하는 함수
bool cmp_gear(int gear_num) {
	char gear_num1_value = getValue(gear_num,1);	//오른쪽 값 
	char gear_num2_value = getValue(gear_num + 1,0);	//왼쪽 값
	if (gear_num1_value==gear_num2_value) {// 같다면 false 반환
		return false;
	}
	else {	//다르다면 true 반환
		return true;
	}
}
void ontime_idx_move(int gear_num, int dir) {
	if (ontime_idx[gear_num] == 7 && dir == -1) {
		ontime_idx[gear_num] = 0;
	}
	else if (ontime_idx[gear_num] == 0 && dir == 1) {
		ontime_idx[gear_num] = 7;
	}
	else {
		ontime_idx[gear_num] += (-dir);
	}
}

void rotation(int gear_num, int dir) {	//톱니 번호, 방향 (1 시계 ,-1 반시계)
	//일단 넘어온 톱니바퀴를 회전한다.
	ontime_idx_move(gear_num, dir);
	//cout << gear_num << ' ' << dir << '\n';
	//맞물린 톱니바퀴 극을 체크한다.
	switch (gear_num)
	{
	case 1:
		if (cmp_check[0]) {
			int next_dir = dir * (-1);
			ontime_idx_move(gear_num + 1, next_dir);
			if (cmp_check[1]) {
				next_dir *= (-1);
				ontime_idx_move(gear_num + 2, next_dir);
				if (cmp_check[2]) {
					next_dir *= (-1);
					ontime_idx_move(gear_num + 3, next_dir);
				}
			}
		}
		break;
	case 2:
		if (cmp_check[0]) {
			int next_dir = dir * (-1);
			ontime_idx_move(gear_num - 1, next_dir);
		}
		if (cmp_check[1]) {
			int next_dir = dir * (-1);
			ontime_idx_move(gear_num + 1, next_dir);
			if (cmp_check[2]) {
				next_dir *= (-1);
				ontime_idx_move(gear_num + 2, next_dir);
			}
		}
		break;
	case 3:
		if (cmp_check[2]) {
			int next_dir = dir * (-1);
			ontime_idx_move(gear_num + 1, next_dir);
		}
		if (cmp_check[1]) {
			int next_dir = dir * (-1);
			ontime_idx_move(gear_num - 1, next_dir);
			if (cmp_check[0]) {
				next_dir *= (-1);
				ontime_idx_move(gear_num - 2, next_dir);
			}
		}
		break;
	case 4:
		if (cmp_check[2]) {
			int next_dir = dir * (-1);
			ontime_idx_move(gear_num - 1, next_dir);
			if (cmp_check[1]) {
				next_dir *= (-1);
				ontime_idx_move(gear_num - 2, next_dir);
				if (cmp_check[0]) {
					next_dir *= (-1);
					ontime_idx_move(gear_num - 3, next_dir);
				}
			}
		}
		break;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> gears[i][j];
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;	
		memset(cmp_check, false, sizeof(cmp_check));
		cin >> a >> b;
		
		//맞물린 톱니 극을 체크한다.
		for (int i = 0; i < 3; i++) {
			if (cmp_gear(i+1)) {
				cmp_check[i] = true;
			}
		}

		rotation(a, b);	//회전하는 함수 호출 (톱니 번호, 방향)
	}
	int ans = 0;
	if (gears[1][ontime_idx[1]] =='1' ) {
		ans += 1;
	}
	if (gears[2][ontime_idx[2]] == '1') {
		ans += 2;
	}	if (gears[3][ontime_idx[3]] == '1') {
		ans +=4;
	}	if (gears[4][ontime_idx[4]] == '1') {
		ans +=8;
	}
	cout << ans << '\n';
	return 0;
}