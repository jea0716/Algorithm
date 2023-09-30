#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int visited[26];
int map[22][22];
int N, M, answer, tmp;
int col[4] = {-1, 0, 1, 0};
int row[4] = {0, -1, 0, 1};

void reset() {
    tmp = 0;
    for(int i=0; i<26; i++) {
        visited[i] = 0;
    }

    return;
}

void solve(int n, int m) {
    visited[map[n][m]] = 1;
    tmp++;
    if(tmp > answer) answer = tmp;

    for(int i=0; i<4; i++) {
        if(n+col[i] >= 0 && n+col[i] < N && m+row[i] >= 0 && m+row[i] < M) {
            if(visited[map[n+col[i]][m+row[i]]] == 0) {
                solve(n+col[i], m+row[i]);
                visited[map[n+col[i]][m+row[i]]] = 0;
                tmp--;
            }
        }
    }

    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    string s;

    for(int i=0; i<N; i++) {
        cin >> s;
        for(int j=0; j<M; j++) {
            map[i][j] = int(s[j] - 'A');
        }
    }

    solve(0, 0);
    cout << answer << "\n";

    return 0;
}