#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int X, Y;
};

int N, M;
int map[301][301];
int visited[301][301];
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

            if(visited[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

void melt(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(map[nx][ny] == 0 && visited[nx][ny] == 1) {
            map[x][y] = map[x][y] - 1 >= 0 ? map[x][y] - 1 : 0;
        }
    }
}

bool check() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] != 0) return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;

    bool divided_check;
    int answer = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }

    while(check()) {
        divided_check = false;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] == 0) visited[i][j] = 1;
                else visited[i][j] = 0;
            }
        }

        for(int i=1; i<N-1; i++) {
            for(int j=1; j<M-1; j++) {
                if(map[i][j] != 0) melt(i, j);
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visited[i][j] == 0) {
                    if(!divided_check) {
                        BFS(i, j);
                        divided_check = true;
                    }
                    else {
                        cout << answer << "\n";
                        return 0;
                    }
                }
            }
        }

        answer++;
    }

    cout << 0 << "\n";

    return 0;
}