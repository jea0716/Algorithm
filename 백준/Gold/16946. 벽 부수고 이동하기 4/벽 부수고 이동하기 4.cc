#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
char map[1001][1001];
int answer[1001][1001];
bool visited[1001][1001];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> wall;
    q.push({ x, y });
    visited[x][y] = true;

    int cnt = 1;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= N) continue;
            if(ny < 0 || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == '0') {
                q.push({ nx, ny });
                visited[nx][ny] = 1;
                cnt++;
            }
            else {
                visited[nx][ny] = 1;
                wall.push_back({ nx, ny });
            }
        }
    }

    for(int i=0; i<wall.size(); i++) {
        answer[wall[i].first][wall[i].second] += cnt;
        visited[wall[i].first][wall[i].second] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == '1') answer[i][j] += 1;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == '0' && !visited[i][j]) BFS(i, j);
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cout << answer[i][j] % 10;
        cout << '\n';
    }

    return 0;
}