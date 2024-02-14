#include <iostream>

using namespace std;

struct node {
    int x, y;
};

int N, M;
int map[501][501];
int visited[501][501];
int answer;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

node shape1[] = {{0, 0}, {0, 1}, {0, 2}, {1, 1}};
node shape2[] = {{0, 0}, {0, 1}, {0, 2}, {-1, 1}};
node shape3[] = {{0, 0}, {1, 0}, {2, 0}, {1, 1}};
node shape4[] = {{0, 0}, {1, 0}, {2, 0}, {1, -1}};

void speacial1(int x, int y){
    int tmp = 0;
    for(int i=0; i<4; i++) {
        int nx = x + shape1[i].x, ny = y + shape1[i].y;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        tmp += map[nx][ny];
    }
    answer = answer > tmp ? answer :tmp;
}

void speacial2(int x, int y){
    int tmp = 0;
    for(int i=0; i<4; i++) {
        int nx = x + shape2[i].x, ny = y + shape2[i].y;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        tmp += map[nx][ny];
    }
    answer = answer > tmp ? answer :tmp;
}

void speacial3(int x, int y){
    int tmp = 0;
    for(int i=0; i<4; i++) {
        int nx = x + shape3[i].x, ny = y + shape3[i].y;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        tmp += map[nx][ny];
    }
    answer = answer > tmp ? answer :tmp;
}

void speacial4(int x, int y){
    int tmp = 0;
    for(int i=0; i<4; i++) {
        int nx = x + shape4[i].x, ny = y + shape4[i].y;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        tmp += map[nx][ny];
    }
    answer = answer > tmp ? answer :tmp;
}

void DFS(int x, int y, int count, int sum) {
    if(count == 4) {
        answer = answer > sum ? answer : sum;
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(visited[nx][ny] == 1) continue;
        visited[nx][ny] = 1;
        DFS(nx, ny, count + 1, sum + map[nx][ny]);
        visited[nx][ny] = 0;
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin >> map[i][j];
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            visited[i][j] = 1;
            DFS(i, j, 1, map[i][j]);
            visited[i][j] = 0;
            speacial1(i, j);
            speacial2(i, j);
            speacial3(i, j);
            speacial4(i, j);
        }
    }

    cout << answer << endl;

    return 0;
}