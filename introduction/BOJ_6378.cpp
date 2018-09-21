#include<iostream>

#include <string>
#include <algorithm>
#include<string.h>

using namespace std;

string func(string num1) {
	long long sum = 0;
	string res;
	while (!num1.empty()) {
		sum += num1.back() - '0';
		num1.pop_back();
	}
	while (sum != 0) {
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	if (res.size()>=2) {
		return func(res);
	}
	else {
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string num;
	cin >> num;
	while (num != "0") {
		cout << func(num) << '\n';
		cin >> num;
	}
	return 0;
}