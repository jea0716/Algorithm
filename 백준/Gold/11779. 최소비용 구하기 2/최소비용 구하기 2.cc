#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9;
int N, M, S, E;
vector<vector<pair<int, int> > > graph(1001);
vector<int> dist(1001, INF);
vector<int> arr(1001);

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({ 0, S });
    dist[S] = 0;

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(auto& edge: graph[cur_node]) {
            int next_node = edge.first;
            int next_dist = edge.second + cur_dist;

            if(dist[next_node] > next_dist) {
                arr[next_node] = cur_node;
                dist[next_node] = next_dist;
                pq.push({ next_dist, next_node });
            }
        }
    }

    cout << dist[E] << '\n';
    vector<int> answer;
    int tmp = E;
    while(tmp) {
        answer.push_back(tmp);
        tmp = arr[tmp];
    }
    cout << answer.size() << '\n';
    for(int i=answer.size()-1; i>=0; i--) cout << answer[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    int to, from, weight;
    for(int i=0; i<M; i++) {
        cin >> to >> from >> weight;
        graph[to].push_back({ from, weight });
    }
    cin >> S >> E;

    dijkstra();

    return 0;
}