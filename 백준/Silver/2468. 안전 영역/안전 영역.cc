#include <iostream>

using namespace std;

int map[102][102];
int visited[102][102];
int N, M;

int col[4] = {-1, 0, 1, 0};
int row[4] = {0, -1, 0, 1};

void bfs(int n, int m, int k) {
    visited[n][m] = 1;
    
    for(int i=0; i<4; i++) {
        if(map[n+col[i]][m+row[i]] > k && visited[n+col[i]][m+row[i]] == 0) {
            bfs(n+col[i], m+row[i], k);
        } 
    }

    return;
}

void reset(int n, int m) {
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) visited[i][j] = 0;
    }

    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    int high = 0, tmp;
    int answer = 0, cnt;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> tmp;
            map[i][j] = tmp;
            if(tmp > high) high = tmp;
        }
    }

    for(int k=0; k<high; k++) {
        reset(N, N);
        cnt = 0;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(map[i][j] > k && visited[i][j] == 0) {
                    cnt++;
                    bfs(i, j, k);
                }
            }
        }
        if(answer < cnt) answer = cnt;
    }

    cout << answer << "\n";

    return 0;
}