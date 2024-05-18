#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int M, N, answer;
int map[501][501];
int dp[501][501];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

int DFS(int x, int y) {
    if(x == N - 1 && y == M - 1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for(int i=0; i<4; i++) {
        if(x + dx[i] < 0 || x + dx[i] >= N) continue;
        if(y + dy[i] < 0 || y + dy[i] >= M) continue;
        if(map[x + dx[i]][y + dy[i]] >= map[x][y]) continue;

        dp[x][y] += DFS(x + dx[i], y + dy[i]);
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << DFS(0, 0) << endl;

    return 0;
}