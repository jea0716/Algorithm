#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, answer;
vector<vector<int>> graph(1001);
bool visited[1001];

void BFS(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while(!q.empty()) {
        int tmp = q.front();
        q.pop();

        for(int i=0; i<graph[tmp].size(); i++) {
            if(!visited[graph[tmp][i]]) {
                q.push(graph[tmp][i]);
                visited[graph[tmp][i]] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;

    int to, from;
    for(int i=0; i<M; i++) {
        cin >> to >> from;
        graph[to].push_back(from);
        graph[from].push_back(to);
    }

    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            BFS(i);
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}