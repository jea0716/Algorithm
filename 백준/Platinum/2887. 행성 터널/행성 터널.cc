#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<pair<int, int>> v[3];
vector<pair<int, int>> graph[100001];
priority_queue<pair<int, int>> pq;
vector<bool> visited(100001);

int main() {
    cin >> N; 

    int x, y, z;
    for(int i=0; i<N; i++) {
        cin >> x >> y >> z;
        v[0].push_back({ x, i });
        v[1].push_back({ y, i });
        v[2].push_back({ z, i });
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());

    for(int i=0; i<N-1; i++) {
        graph[v[0][i].second].push_back({ v[0][i+1].second, abs(v[0][i].first - v[0][i+1].first) });
        graph[v[0][i+1].second].push_back({ v[0][i].second, abs(v[0][i].first - v[0][i+1].first) });
        graph[v[1][i].second].push_back({ v[1][i+1].second, abs(v[1][i].first - v[1][i+1].first) });
        graph[v[1][i+1].second].push_back({ v[1][i].second, abs(v[1][i].first - v[1][i+1].first) });
        graph[v[2][i].second].push_back({ v[2][i+1].second, abs(v[2][i].first - v[2][i+1].first) });
        graph[v[2][i+1].second].push_back({ v[2][i].second, abs(v[2][i].first - v[2][i+1].first) });
    }

    pq.push({ 0, 0 });

    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(visited[cur_node]) continue;

        visited[cur_node] = true;

        for(auto &edge: graph[cur_node]) {
            if(visited[edge.first]) continue;
            pq.push({ -edge.second, edge.first });
        }

        answer += cur_dist;
    }

    cout << answer << endl;

    return 0;
}