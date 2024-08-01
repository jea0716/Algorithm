#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
#define INF 1e9

int N, M;
vector<pair<int, int>> v[50001];
vector<int> answer;

int solve(int n) {
    priority_queue<pair<int, int>> q;
    q.push({ 0, n });
    vector<int> d(N + 1, INF);
    d[n] = 0;

    while(!q.empty()) {
        int dist = -q.top().first;
        int node = q.top().second;
        q.pop();

        if(d[node] < dist) continue;

        for(auto &graph: v[node]) {
            if(d[graph.first] > dist + graph.second) {
                q.push({ -(dist + graph.second), graph.first });
                d[graph.first] = dist + graph.second;
            }
        }
    }
    
    return d[N];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    int A, B, C;
    for(int i=0; i<M; i++) {
        cin >> A >> B >> C;
        v[A].push_back({ B, C });
        v[B].push_back({ A, C });
    }

    cout << solve(1) << '\n';

    return 0;
}