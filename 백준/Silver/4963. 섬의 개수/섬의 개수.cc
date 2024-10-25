#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, cnt;
int map[51][51];
bool visited[51][51];

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

void BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i, j });
    visited[i][j] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= M) continue;
            if(ny < 0 || ny >= N) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == 0) continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    while(N != 0 || M != 0) {
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                cin >> map[i][j];
                visited[i][j] = false;
            }
        }

        int cnt = 0;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(!visited[i][j] && map[i][j] == 1) {
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        cin >> N >> M;
    }

    return 0;
}