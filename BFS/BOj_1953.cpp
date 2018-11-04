#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;
bool visited[101];		//방문했는지 안했는지 체크하는 변수
set<int>blue, white;	//set컨테이너로 blue팀 , white팀 분류
vector<int>v[101];		// 싫어하는 사람 넣는 변수
int n;					
void bfs() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {	//모든 학생들을 체크하기 위한 반복문
		q.push(i);
		while (!q.empty()) {
			int currentNode = q.front();	
			q.pop();
			if (!visited[currentNode]) {	//방문하지 않았다면
				visited[currentNode] = true;
				if (blue.count(currentNode) == 0 && white.count(currentNode) == 0) {//아무데도 안들어가있으면 blue에 넣고
					blue.insert(currentNode);
				}
				for (int i = 0; i < v[currentNode].size(); i++) {
					int nextNode = v[currentNode][i];

					if (!visited[nextNode]) {	//다음노드가 방문 안한 노드라면
						if (blue.count(currentNode) != 0) {	//blue에 현재 노드가 들어있으면 white에 다음노드를 넣는다.
							white.insert(nextNode);
						}
						else if (white.count(currentNode) != 0) {//white에 현재 노드가 들어있으면 blue에 다음노드를 넣는다.
							blue.insert(nextNode);
						}
						q.push(nextNode);
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++) {
			int a;
			cin >> a;
			v[i].push_back(a); v[a].push_back(i);
		}
	}
	bfs();
		set<int>::iterator itr;
	cout << blue.size() << '\n';
	for (itr = blue.begin(); itr != blue.end(); ++itr) {
		cout << *itr << ' ';
	}cout << '\n';
	cout << white.size() << '\n';
	for (itr = white.begin(); itr != white.end(); ++itr) {
		cout << *itr << ' ';
	}cout << '\n';
	return 0;
}