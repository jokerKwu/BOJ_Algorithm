#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int korean, math;
	korean = a / c;
	math = b / d;
	//나누어 떨어지지 않는다면 하루 추가
	if (a%c != 0) {
		korean++;
	}
	if (b%d != 0)
		math++;
	cout << l-max(korean, math) << '\n';//방학기간- 맥스(국어,수학)
	return 0;
}