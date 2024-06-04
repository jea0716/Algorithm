#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, maxCost, answer;
vector<pair<int, int>> graph[100001];
vector<bool> visited(100001);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	int A, B, cost;
	for(int i=0; i<M; i++) {
		cin >> A >> B >> cost;
		graph[A].push_back({ B, cost });
		graph[B].push_back({ A, cost });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	while(!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if(visited[cur_node]) continue;
		visited[cur_node] = 1;

		for(auto &edge: graph[cur_node]) {
			if(!visited[edge.first]) {
				pq.push({ -edge.second, edge.first });
			}
		}

		answer += cur_dist;
		if(cur_dist > maxCost) maxCost = cur_dist;
	}

	cout << answer - maxCost << '\n';

	return 0;
}