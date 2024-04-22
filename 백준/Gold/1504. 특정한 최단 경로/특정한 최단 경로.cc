#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, E, answer = INF;
vector< vector<pair<int, int> > > graph(801);
vector<int> dist(801, INF);

void dijkstra(int s) {
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for(int i=1; i<=N; i++) dist[i] = INF;
    dist[s] = 0;
    pq.push({ 0, s });

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_dist) continue;

        for (auto& edge: graph[cur_node]) {
            int next_node = edge.first;
            int next_dist = edge.second + cur_dist;

            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
}

int main() {
    cin >> N >> E;

    int to, from, weight;
    for(int i=0; i<E; i++) {
        cin >> to >> from >> weight;
        graph[to].push_back({ from, weight });
        graph[from].push_back({ to, weight });
    }

    int n, m; cin >> n >> m;

    dijkstra(1);
    int toN = dist[n];
    int toM = dist[m];

    dijkstra(n);
    int NtoM = dist[m];
    int NtoN = dist[N];

    dijkstra(m);
    int MtoN = dist[N];

    answer = min(answer, toN + NtoM + MtoN);
    answer = min(answer, toM + NtoM + NtoN);

    if(answer >= INF || NtoM == INF) cout << "-1\n";
    else cout << answer << '\n';

    return 0;
}