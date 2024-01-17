#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct coordinate {
    int X, Y;
};

int N;
char map[26][26];
int visited[26][26];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int BFS_SIZE;

int BFS(int x, int y) {
    queue <coordinate> q;
    q.push({ x, y });
    visited[x][y] = 1;
    BFS_SIZE = 1;

    while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(map[nx][ny] == '0' || visited[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            BFS_SIZE++;
            q.push({ nx, ny });
        }
    }

    return BFS_SIZE;
}

int main() {
    cin >> N;
    vector <int> v;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j] == 1) continue;
            if(map[i][j] == '0') continue;
            v.push_back(BFS(i, j));
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++) cout << v[i] << "\n";

    return 0;
}