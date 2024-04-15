#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int x, y;
};

int N, cnt, cnt_RGB;
char c[101];

int map[101][101];
int map_RGB[101][101];
bool visited[101][101];
bool visited_RGB[101][101];

int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};

void BFS(int x, int y) {
    queue <node> q;
    q.push({ x, y });
    visited[x][y] = true;

    while(!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        q.pop();

        for(int i=0; i<4; i++) {
            if(nx + dx[i] < 0 || nx + dx[i] >= N) continue;
            if(ny + dy[i] < 0 || ny + dy[i] >= N) continue;

            if(!visited[nx + dx[i]][ny + dy[i]] && map[nx + dx[i]][ny + dy[i]] == map[x][y]) {
                visited[nx + dx[i]][ny + dy[i]] = true;
                q.push({ nx + dx[i], ny + dy[i] });
            }
        }
    }
}

void BFS_RGB(int x, int y) {
    queue <node> q;
    q.push({ x, y });
    visited_RGB[x][y] = true;

    while(!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        q.pop();

        for(int i=0; i<4; i++) {
            if(nx + dx[i] < 0 || nx + dx[i] >= N) continue;
            if(ny + dy[i] < 0 || ny + dy[i] >= N) continue;

            if(!visited_RGB[nx + dx[i]][ny + dy[i]] && map_RGB[nx + dx[i]][ny + dy[i]] == map_RGB[x][y]) {
                visited_RGB[nx + dx[i]][ny + dy[i]] = true;
                q.push({ nx + dx[i], ny + dy[i] });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> c;
        for(int j=0; j<N; j++) {
            if(c[j] == 'R') {
                map[i][j] = 1;
                map_RGB[i][j] = 1;
            }
            if(c[j] == 'G') {
                map[i][j] = 2;
                map_RGB[i][j] = 1;
            }
            if(c[j] == 'B') {
                map[i][j] = 3;
                map_RGB[i][j] = 2;
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                BFS(i, j);
                cnt++;
            }
            if(!visited_RGB[i][j]) {
                BFS_RGB(i, j);
                cnt_RGB++;
            }
        }
    }

    cout << cnt << " " << cnt_RGB << '\n';

    return 0;
}