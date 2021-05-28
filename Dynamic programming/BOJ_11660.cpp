#include<iostream>

using namespace std;

int N, M;
// pSum[x][y] : x행의 1~y 열 까지의 합
int pSum[1026][1026];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int A;
            cin >> A;
            pSum[i][j] = pSum[i][j - 1] + A;
        }
    }

    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; ++i)
            sum += pSum[i][y2] - pSum[i][y1 - 1];
        cout << sum << '\n';
    }

    return 0;
}