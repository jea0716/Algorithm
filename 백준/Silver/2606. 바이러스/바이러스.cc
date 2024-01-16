#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct route {
    int To, From;
};

int N, M, answer;
vector <vector <int> > v(101);
int visited[101];

void BFS() {
    queue <int> q;
    visited[1] = 1;
    q.push(1);

    while(!q.empty()) {
        int n = q.front();
        q.pop();

        for(int i=0; i<v[n].size(); i++) {
            if(visited[v[n][i]] == 0) {
                visited[v[n][i]] = 1;
                q.push(v[n][i]);
                answer++;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    int to, from;

    for(int i=0; i<M; i++) {
        cin >> to >> from;
        v[to].push_back(from);
        v[from].push_back(to);
    }

    BFS();

    cout << answer << "\n";

    return 0;
}