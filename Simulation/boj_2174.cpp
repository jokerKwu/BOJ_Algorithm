#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 102


typedef struct {
	int index;
	char cmd;
	int loop;
}Robot_Command;

typedef struct {
	int x;
	int y;
	int dir;
	int index;
}Robot_Info;

int m_xy[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
int A, B, N, M;
bool visited[MAX][MAX];
Robot_Info robots[MAX];
vector<Robot_Command> cmds;

void print() {
	cout << "========================================\n";
	for (int i = 1; i <= B; i++) {
		for (int j = 1; j <= A; j++) {
			cout << visited[i][j] << ' ';
		}cout << '\n';
	}
}

int dir_conversion(char ch) {
	switch (ch) {
	case 'N':
		return 0;
		break;
	case 'S':
		return 2;
		break;
	case 'E':
		return 1;
		break;
	case 'W':
		return 3;
		break;
	}

}
int dir_change(int r, int d) {
	if (r == 0) {
		int t_d = d - 1;
		if (t_d < 0) return 3;
		return t_d;
	}
	else {
		int t_d = d + 1;
		if (t_d > 3) return 0;
		return t_d;
	}
}
int find_robot_index(int index,int x, int y) {
	for (int i = 1; i <= N; i++) {
		if (i!=index&&(robots[i].x == x && robots[i].y == y)) {
			return i;
		}
	}
}

void solve() {

	//명령어 하나씩 꺼내서 실행시킨다.
	for (int i = 0; i < cmds.size(); i++) {
		Robot_Command robot_cmd;
		robot_cmd = cmds[i];
		for (int j = 0; j < robot_cmd.loop; j++) {
			Robot_Info robot_info;
			robot_info = robots[robot_cmd.index];
			
			//왼쪽
			if (robot_cmd.cmd == 'L') {
				robot_info.dir = dir_change(0, robot_info.dir);
			}
			//오른쪽
			else if (robot_cmd.cmd == 'R') {
				robot_info.dir = dir_change(1, robot_info.dir);
			}
			//한칸 이동
			else {
				visited[robot_info.y][robot_info.x] = false;
				
				//이동하자
				robot_info.x += m_xy[robot_info.dir][0];
				robot_info.y += m_xy[robot_info.dir][1];
				
				//벽인지 확인
				if (robot_info.x == 0 || robot_info.y == 0 || robot_info.x > A || robot_info.y > B) {
					cout << "Robot "<<robot_info.index<<" crashes into the wall\n";
					return;
				}
				//다른 로봇이랑 충돌났는지 확인
				if (visited[robot_info.y][robot_info.x]) {
					int tmp_index = find_robot_index(robot_info.index,robot_info.x, robot_info.y);
					cout << "Robot "<<robot_info.index<<" crashes into robot "<<tmp_index<<"\n";
					return;
				}
				visited[robot_info.y][robot_info.x] = true;
			}
			robots[robot_cmd.index] = robot_info;
			//print();

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B >> N >> M;
	Robot_Info tmp_info;
	for (int i = 1; i <= N; i++) {
		char dir;
		cin >> tmp_info.x >> tmp_info.y >> dir;
		tmp_info.dir = dir_conversion(dir);
		tmp_info.index = i;
		tmp_info.y = (B - tmp_info.y) + 1;
		visited[tmp_info.y][tmp_info.x] = true;
		robots[i] = tmp_info;
	}
	for (int i = 0; i < M; i++) {
		Robot_Command tmp_cmd;
		cin >> tmp_cmd.index >> tmp_cmd.cmd >> tmp_cmd.loop;
		cmds.push_back(tmp_cmd);
	}
	solve();

	return 0;
}