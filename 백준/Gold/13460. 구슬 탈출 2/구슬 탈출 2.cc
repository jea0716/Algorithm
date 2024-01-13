#include <iostream>
#include <queue>

using namespace std;

struct step{
    int Rx, Ry, Bx, By, Count;
};

int N, M;
char map[11][11];
int visited[11][11][11][11];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void move(int &x, int &y, int &distance, int &i) {
    while(map[x + dx[i]][y + dy[i]] != '#' && map[x][y] != 'O') {
        x += dx[i];
        y += dy[i];
        distance += 1;
    }
}

void BFS(int Rx, int Ry, int Bx, int By) {
    queue <step> q;
    q.push({ Rx, Ry, Bx, By, 0 });
    visited[Rx][Ry][Bx][By] = 1;

    while(!q.empty()) {
        int rx = q.front().Rx;
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        int count = q.front().Count;
        q.pop();

        if(count >= 10) continue;

        for(int i=0; i<4; i++) {
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            int ncount = count + 1;
            int rc = 0, bc = 0;

            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);

            if(map[nbx][nby] == 'O') continue;
            else if(map[nrx][nry] == 'O') {
                cout << ncount << "\n";
                return;
            }

            if(nrx == nbx && nry == nby) {
                if(rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }

            if(visited[nrx][nry][nbx][nby] == 0) {
                visited[nrx][nry][nbx][nby] = 1;
                q.push({ nrx, nry, nbx, nby, ncount});
            }
        }
    }
    cout << "-1\n";
}

int main() {
    int Rx, Ry, Bx, By;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];

            if(map[i][j] == 'R') Rx = i, Ry = j;
            else if(map[i][j] == 'B') Bx = i, By = j;
        }
    }

    BFS(Rx, Ry, Bx, By);

    return 0;
}