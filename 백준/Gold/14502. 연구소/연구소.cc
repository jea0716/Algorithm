#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int map[8][8];
int wall_map[8][8];
int copy_map[8][8];
int col[4] = {-1, 0, 1, 0};
int row[4] = {0, -1, 0, 1};
int answer;

void copyMap(int (*map_a)[8], int (*map_b)[8]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) map_a[i][j] = map_b[i][j];
    }
}

void bfs() {
    copyMap(copy_map, wall_map);
    queue <pair<int, int> > q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(copy_map[i][j] == 2) q.push(make_pair(i, j));
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            if(x+col[i] >= 0 && x+col[i] < N && y+row[i] >= 0 && y+row[i] < M) {
                if(copy_map[x+col[i]][y+row[i]] == 0) {
                    copy_map[x+col[i]][y+row[i]] = 2;
                    q.push(make_pair(x+col[i], y+row[i]));
                }
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(copy_map[i][j] == 0) cnt++;
        }
    }
    if(answer < cnt) answer = cnt;
}

void make_wall(int cnt) {
    if(cnt == 3) bfs();
    else {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(wall_map[i][j] == 0) {
                    wall_map[i][j] = 1;
                    make_wall(cnt+1);
                    wall_map[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin >> map[i][j];
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 0) {
                copyMap(wall_map, map);
                wall_map[i][j] = 1;
                make_wall(1);
            }
        }
    }

    cout << answer << "\n";
}