#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define INF 21000000000000

int N, M, K;
vector<vector<pair<int, int>>> graph(10001);
long long dist[10001][21];

void solve() {
    long long answer = INF;
    for(int i=0; i<=K; i++) {
        answer = answer < dist[N][i] ? answer : dist[N][i];
    }
    cout << answer << '\n';

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;

    int to, from, weight;
    for(int i=0; i<M; i++) {
        cin >> to >> from >> weight;
        graph[to].push_back({ from, weight });
        graph[from].push_back({ to, weight });
    }

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=K; j++) dist[i][j] = INF;
    }

    priority_queue<pair<long long, pair<int, int>>> pq;
    dist[1][0] = 0;
    pq.push({ 0, { 1, 0 } });

    while(!pq.empty()) {
        long long cur_dist = -pq.top().first;
        int cur_node = pq.top().second.first;
        int cur_wall = pq.top().second.second;
        pq.pop();

        if(dist[cur_node][cur_wall] < cur_dist) continue;

        for(auto &edge: graph[cur_node]) {
            int next_node = edge.first;
            long long next_dist = edge.second + cur_dist;

            if(dist[next_node][cur_wall] > next_dist) {
                pq.push({ -next_dist, { next_node, cur_wall }});
                dist[next_node][cur_wall] = next_dist;
            }

            if(cur_wall < K && dist[next_node][cur_wall + 1] > cur_dist) {
                pq.push({ -cur_dist, { next_node, cur_wall + 1 }});
                dist[next_node][cur_wall + 1] = cur_dist;
            }
        }
    }

    solve();

    return 0;
}