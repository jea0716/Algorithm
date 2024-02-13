#include <iostream>
#include <vector>

using namespace std;

int N, M, X, Y, K;
int map[21][21];
int command[1001];
int dice[6] = {0,}; // {위, 현재, 아, 출력부분, 왼, 오}
vector <int> answer;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void solve(int n) {
    int direction = command[n];
    if(X + dx[direction] < 0 || Y + dy[direction] < 0) return;
    if(X + dx[direction] >= N || Y + dy[direction] >= M) return;
    X += dx[direction];
    Y += dy[direction];

    if(command[n] == 1) {
        int tmp = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[4];
        dice[4] = dice[1];
        if(map[X][Y] == 0) dice[1] = tmp, map[X][Y] = tmp;
        else dice[1] = map[X][Y], map[X][Y] = 0;
        cout << dice[3] << "\n";
    }
    else if(command[n] == 2) {
        int tmp = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        if(map[X][Y] == 0) dice[1] = tmp, map[X][Y] = tmp;
        else dice[1] = map[X][Y], map[X][Y] = 0;
        cout << dice[3] << "\n";
    }
    else if(command[n] == 3) {
        int tmp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        if(map[X][Y] == 0) dice[1] = tmp, map[X][Y] = tmp;
        else dice[1] = map[X][Y], map[X][Y] = 0;
        cout << dice[3] << "\n";
    }
    else if(command[n] == 4) {
        int tmp = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[1];
        if(map[X][Y] == 0) dice[1] = tmp, map[X][Y] = tmp;
        else dice[1] = map[X][Y], map[X][Y] = 0;
        cout << dice[3] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M >> X >> Y >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin >> map[i][j];
    }

    for(int i=0; i<K; i++) cin >> command[i];

    for(int i=0; i<K; i++) solve(i);

    return 0;
}