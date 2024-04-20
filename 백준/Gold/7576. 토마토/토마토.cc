#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int y, x, cnt;
};

int N, M, answer;
int map[1001][1001];
bool visited[1001][1001];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

queue<node> q;

void BFS() {
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if(cnt > answer) answer = cnt;

        for(int i=0; i<4; i++) {
            if(x + dx[i] < 0 || x + dx[i] >= M) continue;
            if(y + dy[i] < 0 || y + dy[i] >= N) continue;

            if(!visited[y + dy[i]][x + dx[i]] && map[y + dy[i]][x + dx[i]] == 0) {
                q.push({ y + dy[i], x + dx[i], cnt + 1 });
                visited[y + dy[i]][x + dx[i]] = true;
            }
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[j][i];
            if(map[j][i] == 1) {
                q.push({ j, i, 0 });
                visited[j][i] = true;
            }
            else if(map[j][i] == -1) visited[j][i] = true;
        }
    }

    BFS();

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[j][i]) answer = -1;
        }
    }

    cout << answer << "\n";

    return 0;
}