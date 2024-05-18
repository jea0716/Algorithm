#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9;
int N, M, answer;
vector<vector<pair<int, int>>> graph(1001);
vector<bool> visited(1001, false);

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(visited[cur_node]) continue;

        visited[cur_node] = true;
        answer += cur_dist;

        for(auto &edge: graph[cur_node]) {
            if(visited[edge.first]) continue;
            pq.push({ edge.second, edge.first });
        }
    }

    cout << answer << '\n';

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    int to, from, weight;
    for(int i=0; i<M; i++) {
        cin >> to >> from >> weight;
        graph[to].push_back({ from, weight });
        graph[from].push_back({ to, weight });
    }

    solve();

    return 0;
}