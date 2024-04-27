#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9;
int N, M, X, answer;
vector<vector<pair<int, int> > > graph(1001);

int dijkstra(int s, int e) {
    if(s == e) return 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({ 0, s });
    vector<int> dist(N + 1, INF);

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(auto &edge: graph[cur_node]) {
            int next_node = edge.first;
            int next_dist = edge.second + cur_dist;

            if(dist[next_node] > next_dist) {
                pq.push({ next_dist, next_node });
                dist[next_node] = next_dist;
            }
        }
    }

    return dist[e];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> X;

    int to, from, weight;
    for(int i=0; i<M; i++) {
        cin >> to >> from >> weight;
        graph[to].push_back({ from, weight });
    }

    for(int i=1; i<=N; i++) {
        int stoe = dijkstra(i, X);
        int etos = dijkstra(X, i);

        answer = answer > stoe + etos ? answer : stoe + etos;
    }

    cout << answer << endl;

    return 0;
}