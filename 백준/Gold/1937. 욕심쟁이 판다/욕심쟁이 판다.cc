#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N, answer, tmp;
int arr[501][501];
int dp[501][501];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solve(int x, int y) {
    if(dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N) continue;
        if(ny < 0 || ny >= N) continue;

        if(arr[nx][ny] > arr[x][y]) {
            int tmp = solve(nx, ny) + 1;
            dp[x][y] = dp[x][y] > tmp ? dp[x][y] : tmp;
        }
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int tmp = solve(i, j);
            answer = answer > tmp ? answer : tmp;
        }
    }

    cout << answer << '\n';

    return 0;
}