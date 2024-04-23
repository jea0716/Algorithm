#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, answer;
int map[21][21];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool visited[26];

struct node {
    int x, y, cnt;
    string alpha;
};

bool check(int x, int y, string s) {
    for(int i=0; i<s.length(); i++) {
        if(map[x][y] == s[i]) return false;
    }

    return true;
}

void DFS(int x, int y, int n) {
    if(n > answer) answer = n;

    for(int i=0; i<4; i++) {
        if(x + dx[i] >= N || x + dx[i] < 0) continue;
        if(y + dy[i] >= M || y + dy[i] < 0) continue;

        int tmp = map[x + dx[i]][y + dy[i]];
        if(!visited[tmp]) {
            visited[tmp] = true;
            DFS(x + dx[i], y + dy[i], n + 1);
            visited[tmp] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char c; cin >> c;
            map[i][j] = c - 'A';
        }
    }

    visited[map[0][0]] = true;
    DFS(0, 0, 1);

    cout << answer << endl;
    
    return 0;
}