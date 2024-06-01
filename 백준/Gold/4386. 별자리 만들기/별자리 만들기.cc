#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
double x, y;
// vector<pair<int, pair<double, double>>> v;
vector<pair<double, double>> v;
vector<pair<int, double>> graph[101];
priority_queue<pair<double, int>> pq;

// bool cmpX(const pair<int, pair<double, double>> &n1, const pair<int, pair<double, double>> &n2) {
//     if(n1.second.second == n1.second.second) return n1.second.first < n2.second.first;
//     return n1.second.second < n2.second.second;
// }

// bool cmpY(const pair<int, pair<double, double>> &n1, const pair<int, pair<double, double>> &n2) {
//     if(n1.second.first == n1.second.first) return n1.second.second < n2.second.second;
//     return n1.second.first < n2.second.first;
// }

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
    }

    for(int i=0; i<N; i++) {
        double x = v[i].first;
        double y = v[i].second;
        for(int j=i+1; j<N; j++) {
            double xx = v[j].first;
            double yy = v[j].second;
            double dist = sqrt(((x-xx) * (x-xx)) + ((y-yy) * (y-yy)));
            graph[i].push_back({ j, dist });
            graph[j].push_back({ i, dist });
        }
    }

    double answer = 0;
    for(auto &edge: graph[0]) {
        pq.push({ -edge.second, edge.first });
    }
    vector<bool> visited(N, false);
    visited[0] = true;

    while(!pq.empty()) {
        double cur_dist = -pq.top().first;
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

    cout << answer << '\n';

    return 0;
}