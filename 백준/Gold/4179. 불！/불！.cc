#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N, M, X, Y;
char tmp;
char arr[1001][1001];
bool vis[1001][1001];
int ans = 1e9;
vector<pair<int, int>> f;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Fire() {
    vector<pair<int, int>> tmp;
    tmp.clear();
    int size = f.size();
    for(int i=0; i<size; i++) {
        for(int j=0; j<4; j++) {
            int x = f[i].first + dx[j];
            int y = f[i].second + dy[j];
            if(x < 0 || x >= N) continue;
            if(y < 0 || y >= M) continue;
            if(arr[x][y] == '.') {
                tmp.push_back({ x, y });
                arr[x][y] = 'F';
            }
        }
    }
    f = tmp;
}

void solve() {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 1, { X, Y } });
    vis[X][Y] = 1;
    int curF = 0;

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if(x == 0 || y == 0 || x == N-1 || y == M-1) {
            ans = ans < cnt ? ans : cnt;
        }

        if(curF != cnt) {
            curF++;
            Fire();
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N) continue;
            if(ny < 0 || ny >= M) continue;
            if(arr[nx][ny] == '#') continue;
            if(arr[nx][ny] == 'F') continue;
            if(vis[nx][ny]) continue;

            q.push({ cnt + 1, { nx, ny }});
            vis[nx][ny] = 1;
        }

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> tmp;
            arr[i][j] = tmp;
            if(tmp == 'J') {
                X = i;
                Y = j;
                arr[i][j] = '.';
            }
            if(tmp == 'F') f.push_back({ i, j });
        }
    }

    solve();

    if(ans == 1e9) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';

    return 0;
}