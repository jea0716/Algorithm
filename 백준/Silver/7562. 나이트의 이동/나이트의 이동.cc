#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int K,N;
int to_x, to_y;
int from_x, from_y;
bool visited[301][301];

int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

void clear(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 0;
        }
    }
}

void solve() {
    cin >> N;
    clear(N);
    cin >> to_x >> to_y;
    cin >> from_x >> from_y;

    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { to_x, to_y } });
    visited[to_x][to_y] = 1;

    while(!q.empty()) {
        int cnt = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();

        if(cx == from_x && cy == from_y) {
            cout << cnt << '\n';
            return ;
        }

        for(int i=0; i<8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= N) continue;
            if(ny < 0 || ny >= N) continue;
            if(visited[nx][ny]) continue;

            q.push({ cnt +1 , { nx, ny } });
            visited[nx][ny] = 1;
        }
    }

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> K;

    while(K--) {
        solve();
    }

    return 0;
}