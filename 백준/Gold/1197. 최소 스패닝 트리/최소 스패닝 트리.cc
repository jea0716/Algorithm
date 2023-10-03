#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, A, B, C;
vector <pair<int, int> > graph[10001];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair <int, int> > > pq;
int visited[10001];
int answer;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> V >> E;

    for(int i=0; i<E; i++) {
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
        graph[B].push_back(make_pair(A, C));
    }

    pq.push(make_pair(0, 1));
    
    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;

        visited[node] = 1;

        answer += weight;

        for(int i=0; i<graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = graph[node][i].second;

            pq.push(make_pair(next_weight, next_node));
        }
    }

    cout << answer << "\n";
}