#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<set>
int cnt,n,m;
using namespace std;
typedef pair<int, int> pii;			//x좌표 y좌표
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pii>v,star,dist;
	set<pii>s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		s.insert(make_pair(x,y));
		star.push_back(make_pair(x,y));
	}
	
	pii startPos;
	startPos.first = v[0].first;
	startPos.second = v[0].second;
	//처음 주어진 좌표로 각 좌표마다 거리를 저장한다.
	for (int i = 1; i < v.size(); i++) {
		int distPosX,distPosY;
		distPosX = v[i].first - startPos.first;
		distPosY = v[i].second - startPos.second;
		dist.push_back(make_pair(distPosX,distPosY));
	}
	//입력 받은 별 사진으로부터 각 좌표마다 별자리르 구할수 있는지 체크
	for (int i = 0; i < star.size(); i++) {
		int curPosX = star[i].first;
		int curPosY = star[i].second;
		cnt = 0;
		for (int j = 0; j < dist.size(); j++) {
			pii pos;
			pos.first = curPosX + dist[j].first;
			pos.second = curPosY + dist[j].second;
			if (s.count(make_pair(pos.first, pos.second)) == 1) {
				cnt++;	//거리를 구한 좌표가 존재한다면 카운트
			}
		}
		if (cnt == dist.size()) {		//현재 좌표로 별자리가 존재하는지 체크
			cout << ( curPosX- startPos.first)<<' '<<(curPosY- startPos.second)<<'\n';
			break;
		}
	}
	return 0;
}