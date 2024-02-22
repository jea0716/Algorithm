
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321

struct node {
    int Z, X, Y;
};

int N, M;
int map[1001][1001];
int visited[2][1001][1001];
char c[1001];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS(int z, int x, int y) {
    queue <node> q;
    q.push({ z, x, y });
    visited[z][x][y] = 1;

    while(!q.empty()) {
        node n = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = n.X + dx[i], ny = n.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(map[nx][ny] == 0 && visited[n.Z][nx][ny] > visited[n.Z][n.X][n.Y] + 1) {
                visited[n.Z][nx][ny] = visited[n.Z][n.X][n.Y] + 1;
                q.push({ n.Z, nx, ny });
            }

            if(map[nx][ny] == 1 && n.Z == 0 && visited[n.Z + 1][nx][ny] > visited[n.Z][n.X][n.Y] + 1) {
                visited[n.Z + 1][nx][ny] = visited[n.Z][n.X][n.Y] + 1;
                q.push({ n.Z + 1, nx, ny });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> c;
        for(int j=0; j<M; j++) map[i][j] = c[j] - '0';
    }

    for(int z=0; z<2; z++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) visited[z][i][j] = INF;
        }
    }

    BFS(0, 0, 0);

    int answer = INF;
    for(int i=0; i<2; i++) {
        if(visited[i][N-1][M-1] < answer) answer = visited[i][N-1][M-1];
    }

    if(answer == INF) cout << "-1\n";
    else cout << answer << "\n";

    return 0;
}