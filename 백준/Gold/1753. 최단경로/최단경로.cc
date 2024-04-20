#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int V, E, S;
vector <vector<pair<int, int> > > graph(20001);

void dijkstra(int s) {
    int n = V + 1;
    vector <int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[s] = 0;
    pq.push({ 0, s });

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(auto& edge: graph[cur_node]) {
            int next_node = edge.first;
            int next_dist = edge.second + cur_dist;

            if(next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({ next_dist, next_node });
            }
        }
    }

    for(int i=1; i<=V; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    cin >> V >> E >> S;

    int to, from, weight;
    for(int i=0; i<E; i++) {
        cin >> to >> from >> weight;
        graph[to].push_back({ from, weight });
    }

    dijkstra(S);

    return 0;
}