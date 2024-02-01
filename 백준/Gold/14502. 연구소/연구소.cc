#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int X, Y;
};

int N, M;
int map[10][10];
int tmp_map[10][10];
int visited[10][10];
int virus_visited[10][10];
int answer;

node THREE_WALL[3];
vector <node> virus;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void check() {
    int tmp = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) if(tmp_map[i][j] == 0) tmp++;
    }
    
    if(answer < tmp) answer = tmp;
}

void clear_virus_visited() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) virus_visited[i][j] = 0;
    }
}

void BFS() {
    queue <node> q;
    clear_virus_visited();
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) tmp_map[i][j] = map[i][j];
    }
    for(int i=0; i<3; i++) tmp_map[THREE_WALL[i].X][THREE_WALL[i].Y] = 1;
    for(int i=0; i<3; i++) virus_visited[THREE_WALL[i].X][THREE_WALL[i].Y] = 1;
    for(int i=0; i<virus.size(); i++) q.push(virus[i]);
    for(int i=0; i<virus.size(); i++) virus_visited[virus[i].X][virus[i].Y] = 1;

    while(!q.empty()) {
        node n = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = n.X + dx[i];
            int ny = n.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(tmp_map[nx][ny] != 0 || virus_visited[nx][ny]) continue;
            virus_visited[nx][ny] = 1;
            tmp_map[nx][ny] = 2;
            q.push(node({ nx, ny }));
        }
    }

    check();
}

void DFS(node prev, int count) {
    if(count == 3) {
        BFS();
        return;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(prev.X > i && prev.Y > j) continue;
            if(map[i][j] != 0 || visited[i][j]) continue;
            visited[i][j] = 1;
            THREE_WALL[count] = node({ i, j });
            DFS(node({ i, j }), count + 1);
            visited[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push_back(node({ i, j }));
        }
    }

    DFS(node({ -1, -1 }), 0);

    cout << answer << "\n";

    return 0;
}