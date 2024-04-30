#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9;

struct node {
    int x, y, cnt, wall;
};

int N, M, K, answer = INF;
int map[1001][1001];
int visited[1001][1001][11];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

void BFS() {
    queue <node> q;
    q.push({ 0, 0, 1, 0 });
    visited[0][0][0] = true;

    while(!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        int ncnt = q.front().cnt;
        int nwall = q.front().wall;
        q.pop();

        if(ncnt > answer) continue;
        if(nx == N - 1 && ny == M - 1) answer = ncnt;

        for(int i=0; i<4; i++) {
            if(nx + dx[i] < 0 || nx + dx[i] >= N) continue;
            if(ny + dy[i] < 0 || ny + dy[i] >= M) continue;
            if(visited[nx + dx[i]][ny + dy[i]][nwall]) continue;

            if(map[nx + dx[i]][ny + dy[i]] == 1 && nwall < K && !visited[nx + dx[i]][ny + dy[i]][nwall - 1]) {
                q.push({ nx + dx[i], ny + dy[i], ncnt + 1, nwall + 1 });
                visited[nx + dx[i]][ny + dy[i]][nwall + 1] = true;
            }

            if(map[nx + dx[i]][ny + dy[i]] == 0) {
                q.push({ nx + dx[i], ny + dy[i], ncnt + 1, nwall });
                visited[nx + dx[i]][ny + dy[i]][nwall] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;

    char c;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    BFS();

    if(answer == INF) answer = -1;
    cout << answer << endl;

    return 0;
}