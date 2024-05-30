#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int x, y;
    char a;
};

int T, N, M;
char map[101][101];
bool visited[101][101];
vector<bool> key(26);
vector<pair<int, int>> v[26];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

void BFS() {
    int answer = 0;
    queue<pair<int, int>> q;
    for(int i=0; i<N; i++) {
        if(map[i][0] == '.' || map[i][0] == '$') {
            q.push({ i, 0 });
        }
        if(map[i][0] >= 'A' && map[i][0] <= 'Z') {
            if(key[map[i][0] - 'A']) {
                q.push({ i, 0 });
            }
            else v[map[i][0] - 'A'].push_back({ i, 0 });
        }
        if(map[i][0] >= 'a' && map[i][0] <= 'z') {
            key[map[i][0] - 'a'] = true;
            q.push({ i, 0 });
        }
        if(map[i][M-1] == '.' || map[i][M-1] == '$') {
            q.push({ i, M-1 });
        }
        if(map[i][M-1] >= 'A' && map[i][M-1] <= 'Z') {
            if(key[map[i][M-1] - 'A']) {
                q.push({ i, M-1 });
            }
            else v[map[i][M-1] - 'A'].push_back({ i, M-1 });
        }
        if(map[i][M-1] >= 'a' && map[i][M-1] <= 'z') {
            key[map[i][M-1] - 'a'] = true;
            q.push({ i, M-1 });
        }
    }
    for(int i=0; i<M; i++) {
        if(map[0][i] == '.' || map[0][i] == '$') {
            q.push({ 0, i });
        }
        if(map[0][i] >= 'A' && map[0][i] <= 'Z') {
            if(key[map[0][i] - 'A']) {
                q.push({ 0, i });
            }
            else v[map[0][i] - 'A'].push_back({ 0, i });
        }
        if(map[0][i] >= 'a' && map[0][i] <= 'z') {
            key[map[0][i] - 'a'] = true;
            q.push({ 0, i });
        }
        if(map[N-1][i] == '.' || map[N-1][i] == '$') {
            q.push({ N-1, i });
        }
        if(map[N-1][i] >= 'A' && map[N-1][i] <= 'Z') {
            if(key[map[N-1][i] - 'A']) {
                q.push({ N-1, i });
            }
            else v[map[N-1][i] - 'A'].push_back({ N-1, i });
        }
        if(map[N-1][i] >= 'a' && map[N-1][i] <= 'z') {
            key[map[N-1][i] - 'a'] = true;
            q.push({ N-1, i });
        }
    }

    for(int i=0; i<key.size(); i++) {
        if(key[i]) {
            while(!v[i].empty()) {
                q.push({ v[i].back().first, v[i].back().second });
                v[i].pop_back();
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(visited[x][y]) continue;
        if(map[x][y] == '$') answer++;
        visited[x][y] = 1;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N) continue;
            if(ny < 0 || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == '.' || map[nx][ny] == '$') {
                q.push({ nx, ny });
            }
            else if(map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
                if(key[map[nx][ny] - 'A']) {
                    q.push({ nx, ny });
                }
                else {
                    v[map[nx][ny] - 'A'].push_back({ nx, ny });
                }
            }
            else if(map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
                q.push({ nx, ny });
                key[map[nx][ny] - 'a'] = 1;
                while(!v[map[nx][ny] - 'a'].empty()) {
                    q.push({ v[map[nx][ny] - 'a'].back().first, v[map[nx][ny] - 'a'].back().second });
                    v[map[nx][ny] - 'a'].pop_back();
                }
            }
        }
    }

    cout << answer << '\n';

    return ;
}

void solve() {
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin >> map[i][j];
    }

    for(int i=0; i<26; i++) {
        key[i] = false;
        v[i].clear();
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) visited[i][j] = 0;
    }

    string s;
    cin >> s;

    if(s != "0") {
        for(int i=0; i<s.length(); i++) key[s[i] - 'a'] = true;
    }

    BFS();

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;

    for(int i=0; i<T; i++) solve();

    return 0;
}