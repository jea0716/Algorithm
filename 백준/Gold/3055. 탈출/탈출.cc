#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct node {
    int x, y, cnt;
    bool type;
};

int N, M, answer = 1e9;
char map[51][51];
bool visited[51][51];
vector<node> water;
node s, e;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS() {
    queue<node> q;
    for(int i=0; i<water.size(); i++) q.push(water[i]);
    q.push(s);

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        bool type = q.front().type;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N) continue;
            if(ny < 0 || ny >= M) continue;

            if(!type && nx == e.x && ny == e.y) {
                answer = answer < cnt + 1 ? answer : cnt + 1;
            } 

            if(type) {
                if(map[nx][ny] == '.' && !visited[nx][ny]) {
                    q.push({ nx, ny, cnt + 1, true });
                    map[nx][ny] = '*';
                    visited[nx][ny] = true;
                }
            }
            else {
                if(map[nx][ny] == '.' && !visited[nx][ny]) {
                    q.push({ nx, ny, cnt + 1, false });
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == '*') water.push_back({ i, j, 0, true });
            else if(map[i][j] == 'S') s = { i, j, 0, false };
            else if(map[i][j] == 'D') e = { i, j, 0, false };
        }
    }

    BFS();

    if(answer != 1e9) cout << answer << '\n';
    else cout << "KAKTUS\n";

    return 0;
}