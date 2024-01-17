#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct path {
    int N, Count;
};

int N, M;
vector <vector <int> > v(101);
int visited[101];

int BFS(int to, int from) {
    queue <path> q;
    q.push({ to, 0 });
    visited[to] = 1;

    while(!q.empty()) {
        int n = q.front().N;
        int count = q.front().Count;
        q.pop();

        if(n == from) return count;

        for(int i=0; i<v[n].size(); i++) {
            if(visited[v[n][i]] == 1) continue;
            visited[v[n][i]] = 1;
            q.push({ v[n][i], count + 1 });
        }
    }

    return -1;
}

int main() {
    int to, from, x, y;
    cin >> N >> to >> from >> M;

    for(int i=0; i<M; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout << BFS(to, from) << "\n";
}