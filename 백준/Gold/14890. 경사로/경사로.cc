#include <iostream>

using namespace std;

int N, M;
int map[101][101];
int answer;
int visited[101];

bool check_row(int n) {
    for(int i=0; i<N; i++) visited[i] = 0;
    int prev;
    for(int i=0; i<N; i++) {
        if(i == 0) prev = map[n][i];
        else prev = map[n][i-1];
        if(abs(prev - map[n][i]) > 1) return false;

        if(prev - map[n][i] == 1) {
            for(int j=0; j<M; j++) {
                if(map[n][i] != map[n][i+j] || visited[i+j] || i + j >= N) return false;
                else visited[i+j] = 1;
            }
            i = i + M - 1;
        }
    }
    for(int i=N-1; i>=0; i--) {
        if(i==N-1) prev = map[n][i];
        else prev = map[n][i+1];

        if(prev - map[n][i] == 1) {
            for(int j=0; j<M; j++) {
                if(map[n][i] != map[n][i-j] || visited[i-j] || i -j < 0) return false;
                else visited[i-j] = 1;
            }
            i = i - M + 1;
        }
    }

    return true;
}

bool check_col(int n) {
    for(int i=0; i<N; i++) visited[i] = 0;
    int prev;
    for(int i=0; i<N; i++) {
        if(i == 0) prev = map[i][n];
        else prev = map[i-1][n];
        if(abs(prev - map[i][n]) > 1) return false;

        if(prev - map[i][n] == 1) {
            for(int j=0; j<M; j++) {
                if(map[i][n] != map[i+j][n] || visited[i+j] || i + j >= N) return false;
                else visited[i+j] = 1;
            }
            i = i + M - 1;
        }
    }
    for(int i=N-1; i>=0; i--) {
        if(i==N-1) prev = map[i][n];
        else prev = map[i+1][n];

        if(prev - map[i][n] == 1) {
            for(int j=0; j<M; j++) {
                if(map[i][n] != map[i-j][n] || visited[i-j] || i -j < 0) return false;
                else visited[i-j] = 1;
            }
            i = i - M + 1;
        }
    }

    return true;
}

void solve() {
    int prev = 0;
    for(int i=0; i<N; i++) {
        if(check_row(i)) answer++;
        if(check_col(i)) answer++;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> map[i][j];
    }

    solve();

    cout << answer << endl;

    return 0;
}