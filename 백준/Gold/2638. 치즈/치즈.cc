#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int x, y;
};

int N, M;
int map[101][101];
int visited[101][101];
vector <node> v;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

bool check() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 1) return true;
        }
    }

    return false;
}

void clear_visited() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) visited[i][j] = 0;
    }
}

void BFS() {
    queue <node> q;
    q.push({ 0, 0 });
    visited[0][0] = 1;

    while(!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        q.pop();

        for(int i=0; i<4; i++) {
            if(nx + dx[i] >= N || nx + dx[i] < 0) continue;
            if(ny + dy[i] >= M || ny + dy[i] < 0) continue;

            if(map[nx + dx[i]][ny + dy[i]] == 0 && !visited[nx + dx[i]][ny + dy[i]]) {
                q.push({ nx + dx[i], ny + dy[i] });
                visited[nx + dx[i]][ny + dy[i]]++;
            }

            if(map[nx + dx[i]][ny + dy[i]] == 1) {
                visited[nx + dx[i]][ny + dy[i]]++;
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visited[i][j] >= 2) map[i][j]--;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin >> map[i][j];
    }

    int cnt = 0;

    while(check()) {
        clear_visited();
        BFS();
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}