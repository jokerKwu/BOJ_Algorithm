#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
#define MAX 102
int R, C,M;
typedef pair<int,pair<int,pair<int, pair<int, int> > > > piiiii;	//r 행 c 열 s 속력 d 이동방향 z 크기
vector<piiiii>shakes; // r ,c , s ,d ,z  행 열 속력 방향 크기 상어 정보들
int shakes_board[MAX][MAX]; //맵에 상어가 있는지 상어 크기로 표시
int m_xy[5][2] = { {0,0},{0,-1},{0,1},{1,0},{-1,0} };
int ans = 0;

void print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << shakes_board[i][j] << ' ';
		}cout << '\n';
	}
}

bool range_check(int x, int y) {
	if (x >= 1 && x <= C && y >= 1 && y <= R)	return true;
	else return false;
}

void bfs() {
	queue<piiiii>q;
	//사람을 먼저 넣고  그다음 상어를 넣는다.
	q.push(make_pair(0, make_pair(0, make_pair(-1, make_pair(3, 0)))));
	for (int i = 0; i < shakes.size(); i++) {
		int r = shakes[i].first;
		int c = shakes[i].second.first;
		int s = shakes[i].second.second.first;
		int d = shakes[i].second.second.second.first;
		int z = shakes[i].second.second.second.second;
		q.push(make_pair(r, make_pair(c, make_pair(s, make_pair(d, z)))));
	}
	int time = 1;
	vector<piiiii>new_shakes;
	while (!q.empty()) {
		//상어 꺼내고요
		int c_r = q.front().first;
		int c_c = q.front().second.first;
		int c_s = q.front().second.second.first;
		int c_d = q.front().second.second.second.first;
		int c_z = q.front().second.second.second.second;
		//cout << c_r << ' ' << c_c << ' ' << c_s << ' ' << c_d << ' ' << c_z << '\n';
		q.pop();
		
		//사람이면 맵을 갱신 한칸 이동 상어 잡고 
		if (c_s == -1) {
			//상어를 새롭게 갱신하고 
			for (int i = 0; i < new_shakes.size(); i++) {
				int t_r = new_shakes[i].first;
				int t_c = new_shakes[i].second.first;
				int t_s = new_shakes[i].second.second.first;
				int t_d = new_shakes[i].second.second.second.first;
				int t_z = new_shakes[i].second.second.second.second;

				//상어 갱신할때 상어가 존재하면 크기 비교해서 넣을지 말지 판단
				if (shakes_board[t_r][t_c] != 0) { //충돌 발생
					if (shakes_board[t_r][t_c] < t_z) {
						shakes_board[t_r][t_c] = t_z;
						q.push(make_pair(t_r, make_pair(t_c, make_pair(t_s, make_pair(t_d, t_z)))));
					}
				}
				else { //미충돌
					shakes_board[t_r][t_c] = t_z;
					q.push(make_pair(t_r, make_pair(t_c, make_pair(t_s, make_pair(t_d, t_z)))));
				}
			}
			//cout << "-======================맵 \n";
			//print();
			//cout << "-======================맵 \n";

			new_shakes.clear();
			//사람일때마다 카운트해서 끝에 도달했는지 체크한다.

			c_c += 1;
			if (c_c > C) {	//종료 시키는 조건문

				return;
			}
			//오른쪽 한칸 이동 후 그 열에 상어가 있는지 체크한다.
			//상어가 있다면 가장 가까운놈 없앤다.
			for (int y = 1; y <= R; y++) {
				if (shakes_board[y][c_c]!=0) {
					ans += shakes_board[y][c_c];
					shakes_board[y][c_c] = 0;
					break;
				}
			}
			
			q.push(make_pair(c_r, make_pair(c_c, make_pair(c_s, make_pair(c_d, c_z)))));
		}

		//상어면 이동시킨다
		if (shakes_board[c_r][c_c]==c_z&&c_s!=-1) {	//안없어지고 존재한다면 다음 좌표 이동 시킨다.
			shakes_board[c_r][c_c] = 0;
			//cout << c_r << ' ' << c_c << '\n';
			//상어 이동시키면 되는데 주의할점이 벽에 부딪히면 반대방향으로 이동해야됨
			for (int i = 0; i < c_s; i++) {
				int n_r = c_r + m_xy[c_d][1];
				int n_c = c_c + m_xy[c_d][0];
				if (range_check(n_c, n_r)) {//범위 안이라면
					c_r = n_r;
					c_c = n_c;
				}
				else {//범위 밖이라면
					switch (c_d) {
					case 1:
						c_d = 2;
						break;
					case 2:
						c_d = 1;
						break;
					case 3:
						c_d = 4;
						break;
					case 4:
						c_d = 3;
						break;
					}

					c_r =c_r+ m_xy[c_d][1];
					c_c =c_c+ m_xy[c_d][0];
				}
			}
			new_shakes.push_back(make_pair(c_r, make_pair(c_c, make_pair(c_s, make_pair(c_d, c_z)))));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shakes_board[r][c] = z;
		shakes.push_back(make_pair(r, make_pair(c, make_pair(s, make_pair(d, z)))));
	}
	bfs();
	cout << ans << '\n';
	return 0;
}