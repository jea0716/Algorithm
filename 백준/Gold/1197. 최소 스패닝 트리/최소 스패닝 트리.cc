#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int V, E, answer;
vector<bool> visited(10001);
vector<vector<pair<int, int>>> map(10001);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> V >> E;

    int A, B, C;
    for(int i=0; i<E; i++) {
        cin >> A >> B >> C;
        map[A].push_back({ B, C });
        map[B].push_back({ A, C });
    }

    pq.push({ 0, 1 });
    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(visited[cur_node]) continue;

        visited[cur_node] = true;
        answer += cur_dist;

        for(auto edge: map[cur_node]) {
            if(visited[edge.first]) continue;
            pq.push({ edge.second, edge.first });
        }
    }

    cout << answer << '\n';

    return 0;
}