#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct node {
    int dist, x, y;
};

struct compare {
    bool operator()(const node& n1, const node& n2) {
        if(n1.dist == n2.dist) {
            if(n1.x == n2.x) {
                return n1.y > n2.y;
            }   
            return n1.x > n2.x;
        }
        return n1.dist > n2.dist;
    }
};

int N;
int map[21][21];
int x, y, weight = 2, ate = 0, sec = 0;
bool visited[21][21], exist = true;
priority_queue<node, vector<node>, compare> fishes;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void BFS() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            visited[i][j] = false;
        }
    }
    queue<node> q;
    q.push({ 0, x, y });
    visited[x][y] = true;
    int min_dist = 1e9;


    while(!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        int ndist = q.front().dist;
        q.pop();

        if(ndist > min_dist) continue;

        if(map[nx][ny] > 0 && map[nx][ny] < weight) {
            fishes.push({ ndist, nx, ny });
            if(min_dist > ndist) min_dist = ndist;
        }

        for(int i=0; i<4; i++) {
            if(nx + dx[i] < 0 || nx + dx[i] >= N) continue;
            if(ny + dy[i] < 0 || ny + dy[i] >= N) continue;
            if(visited[nx + dx[i]][ny + dy[i]]) continue;
            if(map[nx + dx[i]][ny + dy[i]] > weight) continue;

            q.push({ ndist + 1, nx + dx[i], ny + dy[i] });
            visited[nx + dx[i]][ny +dy[i]] = true;
        }
    }

    if(!fishes.empty()) {
        node tmp = fishes.top();
        sec += tmp.dist;
        map[x][y] = 0;
        x = tmp.x;
        y = tmp.y;
        map[tmp.x][tmp.y] = 9;
        ate++;
        if(ate == weight) {
            weight = weight + 1 > 8 ? 8 : weight + 1;
            ate = 0;
        }
        while(!fishes.empty()) fishes.pop();
    }
    else exist = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                x = i;
                y = j;
            }
        }
    }

    while(exist) {
        BFS();
    }

    cout << sec << endl;

    return 0;
}