#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct coordinate {
    int X, Y, Count;
};

int N, M;
char map[101][101];
int visited[101][101];
int answer = 9999999;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS() {
    queue <coordinate> q;
    visited[0][0] = 1;
    q.push({0, 0, 1});

    while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        int count = q.front().Count;
        q.pop();

        if(x == N-1 && y == M-1 && answer > count) {
            answer = count;
        }

        for(int i=0; i<4; i++) {
            if(
                x + dx[i] >= 0 && 
                y + dy[i] >= 0 && 
                x + dx[i] < N &&
                y + dy[i] < M &&
                map[x + dx[i]][y + dy[i]] == '1' &&
                visited[x + dx[i]][y + dy[i]] == 0
                ) {
                    visited[x + dx[i]][y + dy[i]] = 1;
                    q.push({x + dx[i], y + dy[i], count + 1});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    string s;

    for(int i=0; i<N; i++) {
        cin >> s;
        for(int j=0; j<s.length(); j++) {
            map[i][j] = s[j];
        }
    }

    BFS();

    cout << answer << "\n";

    return 0;
}