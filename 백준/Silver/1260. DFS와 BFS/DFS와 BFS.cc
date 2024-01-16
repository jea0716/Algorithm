#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
int to, from;
vector <vector <int> > v(1001);
int BFS_VISIT[1001];
int DFS_VISIT[1001];
vector <int> ANSWER_DFS;
vector <int> ANSWER_BFS;

void DFS(int start) {
    ANSWER_DFS.push_back(start);
    DFS_VISIT[start] = 1;

    for(int i=0; i<v[start].size(); i++) {
        if(DFS_VISIT[v[start][i]] == 0) {
            DFS(v[start][i]);
        }
    }
}

void BFS(int start) {
    queue <int> q;
    q.push(start);
    BFS_VISIT[start] = 1;
    ANSWER_BFS.push_back(start);

    while(!q.empty()) {
        int n = q.front();
        q.pop();

        for(int i=0; i<v[n].size(); i++) {
            if(BFS_VISIT[v[n][i]] == 0) {
                BFS_VISIT[v[n][i]] = 1;
                q.push(v[n][i]);
                ANSWER_BFS.push_back(v[n][i]);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    for(int i=0; i<M; i++) {
        cin >> to >> from;
        v[to].push_back(from);
        v[from].push_back(to);
        sort(v[to].begin(), v[to].end());
        sort(v[from].begin(), v[from].end());
    }

    DFS(V);
    BFS(V);

    for(int i=0; i<ANSWER_DFS.size(); i++) {
        cout << ANSWER_DFS[i] << " ";
    }
    cout << "\n";

    for(int i=0; i<ANSWER_BFS.size(); i++) {
        cout << ANSWER_BFS[i] << " ";
    }
    cout << "\n";

    return 0;
}