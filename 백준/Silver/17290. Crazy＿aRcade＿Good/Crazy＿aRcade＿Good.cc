#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int X, Y, answer = 1e9;
char map[10][10];
bool safe[10][10];
bool visited[10][10];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> X >> Y;

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'o') {
                for(int k=0; k<10; k++) {
                    safe[i][k] = true;
                    safe[k][j] = true;
                }
            }
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { X -1 , Y - 1 } });
    visited[X - 1][Y - 1] = true;

    while(!q.empty()) {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(!safe[x][y]) {
            answer = answer < cnt ? answer : cnt;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= 10) continue;
            if(ny < 0 || ny >= 10) continue;
            if(map[nx][ny] == 'o') continue;
            if(visited[nx][ny]) continue;

            q.push({ cnt + 1, { nx, ny } });
            visited[nx][ny] = true;
        }
    }

    cout << answer << '\n';

    return 0;
}   