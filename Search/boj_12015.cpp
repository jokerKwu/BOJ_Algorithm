#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAX 1000001
vector<int>arr;
int res[MAX];
int binarySearch(int findN,int size) {
	int left = 0, right = size - 1;
	int index = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (findN < res[mid]) {
			right = mid - 1;
		}
		else if (findN > res[mid]) {
			left = mid + 1;
			index = left;
		}
		else {
			index = mid;
			break;
		}
	}
	return index;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	res[0]=arr[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		int index = binarySearch(arr[i], cnt);
		res[index] = arr[i];
		if (index == cnt) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}