#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C, T;
int map[51][51];
int diff[51][51];
vector<pair<int, int>> airconditioner;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void diffusion() {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[i][j] != 0 && map[i][j] != -1) {
                vector<int> tmp;
                for(int k=0; k<4; k++) {
                    if(i + dx[k] < 0 || i + dx[k] >= R) continue;
                    if(j + dy[k] < 0 || j + dy[k] >= C) continue;
                    if(map[i + dx[k]][j + dy[k]] == -1) continue;
                    tmp.push_back(k);
                }
                int air = map[i][j] / 5;
                map[i][j] -= air * tmp.size();
                for(int k=0; k<tmp.size(); k++) {
                    diff[i + dx[tmp[k]]][j + dy[tmp[k]]] += air;
                }
                while(!tmp.empty()) {
                    tmp.pop_back();
                }
            }
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            map[i][j] += diff[i][j];
            diff[i][j] = 0;
        }
    }
}

void work() {
    int upX = airconditioner[0].first;
    int upY = airconditioner[0].second + 1;
    int downX = airconditioner[1].first;
    int downY = airconditioner[1].second + 1;
    int upAir = 0, downAir = 0, tmp;

    while(upY < C) {
        tmp = map[upX][upY];
        map[upX][upY] = upAir;
        upAir = tmp;
        upY++;

        tmp = map[downX][downY];
        map[downX][downY] = downAir;
        downAir = tmp;
        downY++;
    }

    upX--; upY--;
    while(upX >= 0) {
        tmp = map[upX][upY];
        map[upX][upY] = upAir;
        upAir = tmp;
        upX--;
    }

    downX++; downY--;
    while(downX < R) {
        tmp = map[downX][downY];
        map[downX][downY] = downAir;
        downAir = tmp;
        downX++;
    }

    upX++; upY--;
    downX--; downY--;
    while(upY >= 0) {
        tmp = map[upX][upY];
        map[upX][upY] = upAir;
        upAir = tmp;
        upY--;

        tmp = map[downX][downY];
        map[downX][downY] = downAir;
        downAir = tmp;
        downY--;
    }

    downY++; downX--;
    while(map[downX][downY] != -1) {
        tmp = map[downX][downY];
        map[downX][downY] = downAir;
        downAir = tmp;
        downX--;
    }

    upY++; upX++;
    while(map[upX][upY] != -1) {
        tmp = map[upX][upY];
        map[upX][upY] = upAir;
        upAir = tmp;
        upX++;
    }

}

int check() {
    int air = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[i][j] != -1) {
                air += map[i][j];
            }
        }
    }
    return air;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C >> T;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) {
                airconditioner.push_back({ i, j });
            }
        }
    }

    for(int i=0; i<T; i++) {
        diffusion();
        work();
    }

    cout << check() << "\n";

    return 0;
}