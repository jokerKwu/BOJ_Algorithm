#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long x[4], y[4], s[6];

int main()
{
	int i, j, k, tc;
	cin >> tc;
	while (tc--)
	{
		k = 0;
		for (i = 0; i < 4; i++)
			cin >> x[i] >> y[i];

		//각 점들마다 이동할 수 있는 좌표간에 거리를 모두 구합니다.
		for (i = 0; i < 4; i++)	
			for (j = i + 1; j < 4; j++)
			{
				s[k] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
				k++;
			}

		sort(s, s + 6);	//정렬을 통해서 앞에 4개 길이는 정사각형 네 변에 길이이고 나머지 2개는 정사각형에 두 대각선 길이입니다.
		cout << (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5]) << '\n';
	}
}