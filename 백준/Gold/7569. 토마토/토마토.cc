#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coordinate {
    int X, Y, Z, Count;
};

int M, N, H;
int map[101][101][101];
int visited[101][101][101];
int dz[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};
int answer;

void BFS(queue <coordinate> q) {
    int tmp;
    while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        int z = q.front().Z;
        int count = q.front().Count;
        q.pop();

        if(answer < count) answer = count;

        for(int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            int ncount = count + 1;

            if(nx < 0 || ny < 0 || nz < 0) continue;
            if(nx >= N || ny >= M || nz >= H) continue;
            if(visited[nx][ny][nz] != 0) continue;
            visited[nx][ny][nz] = 1;
            q.push({ nx, ny, nz, ncount });
        }
    }
}

int main() {
    cin >> M >> N >> H;
    queue <coordinate> q;

    for(int k=0; k<H; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 1) {
                    visited[i][j][k] = 1;
                    q.push({ i, j, k, 0 });
                }
                else if(map[i][j][k] == -1) {
                    visited[i][j][k] = 1;
                }
            }
        }
    }

    BFS(q);

    for(int k=0; k<H; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visited[i][j][k] == 0) answer = -1;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}