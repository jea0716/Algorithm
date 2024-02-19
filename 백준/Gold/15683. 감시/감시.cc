#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int X, Y;
};

int N, M;
int map[10][10];
int tmp[9][9];
vector <node> cctv;
int answer = 987654321;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

void check(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if(map[nx][ny] == 6) return;
        if(map[nx][ny] != 0) continue;
        map[nx][ny] = -1;
    }
}

void DFS(int count){
    if(count == cctv.size()){
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) if(!map[i][j]) cnt++;
        }

        answer = answer < cnt ? answer : cnt;
        return;
    }
    
    int x = cctv[count].X, y = cctv[count].Y;
    int tmp[9][9];

    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) tmp[i][j] = map[i][j];
        }

        if(map[x][y] == 1) {
            check(x, y, dir);
        }
        else if(map[x][y] == 2){
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (map[x][y] == 3){
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (map[x][y] == 4){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2); 
        }
        else if (map[x][y] == 5){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        DFS(count+1);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) map[i][j] = tmp[i][j];
        }
    }    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6) cctv.push_back({ i, j });
        }
    }

    DFS(0);
    cout << answer << "\n";

    return 0;
}