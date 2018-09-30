#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<string>
using namespace std;
int Reverse(int n) {
	char tmp[4];
	memset(tmp, '\0', sizeof(tmp));
	int idx = 0;
	while (n != 0) {
		tmp[idx++] = (n % 10) + '0';
		n /= 10;
	}
	int k=0,j = 0;
	while (j < idx) {
		k = (k*10)+(tmp[j] - '0');
		j++;
	}
	return k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	x = Reverse(x);
	y = Reverse(y);
	cout << Reverse(x + y) << '\n';
	return 0;
}