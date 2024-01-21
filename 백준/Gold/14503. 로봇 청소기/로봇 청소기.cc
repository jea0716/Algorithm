#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int X, Y, D;
};

int N, M;
node cleaner;
int map[51][51];
int visited[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int answer;

void DFS(node n) {
    for(int i=1; i<=4; i++) {
        int nd = (4 + n.D - i) % 4;
        int nx = n.X + dx[nd];
        int ny = n.Y + dy[nd];

        if(map[nx][ny] == 1 || visited[nx][ny] == 1) continue;

        node next_node = { nx, ny, nd };
        visited[nx][ny] = 1;
        answer++;
        DFS(next_node);
    }

    int bd = (n.D + 2) % 4;
    int bx = n.X + dx[bd];
    int by = n.Y + dy[bd];

    if(map[bx][by] == 1) {
        cout << answer << endl;
        exit(0);
    }
    else DFS({ bx, by, n.D });
}

int main() {
    cin >> N >> M;
    cin >> cleaner.X >> cleaner.Y >> cleaner.D;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            // if(map[i][j] == 1) visited[i][j] = 1;
        }
    }

    answer = 1;
    visited[cleaner.X][cleaner.Y] = 1;
    DFS(cleaner);

    return 0;
}