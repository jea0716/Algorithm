#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int X, Y;
};

int N, MAX_HEIGHT;
int map[101][101];
int visited[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS(int x, int y) {
    queue <node> q;
    q.push({ x, y });
    visited[x][y] = 1;

    while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visited[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

int main() {
    int answer = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            MAX_HEIGHT = MAX_HEIGHT > map[i][j] ? MAX_HEIGHT : map[i][j];
        }
    }

    for(int k=0; k<=MAX_HEIGHT; k++) {
        int count = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] <= k) visited[i][j] = 1;
                else visited[i][j] = 0;
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(visited[i][j] == 0) {
                    BFS(i, j);
                    count++;
                }
            }
        }
        
        answer = answer > count ? answer : count;
    }

    cout << answer << "\n";

    return 0;
}