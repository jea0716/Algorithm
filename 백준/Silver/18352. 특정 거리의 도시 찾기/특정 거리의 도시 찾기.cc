#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, K, X;
vector<int> v[300001];
bool visited[300001];
vector<int> answer;

void solve(int n) {
    queue<pair<int, int>> q;
    q.push({ 0, n });
    visited[n] = 1;

    while(!q.empty()) {
        int dist = -q.front().first;
        int node = q.front().second;
        q.pop();

        if(dist == K) answer.push_back(node);

        for(auto graph: v[node]) {
            if(visited[graph]) continue;
            
            q.push({ -(dist + 1), graph });
            visited[graph] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> K >> X;

    int A, B;
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        v[A].push_back(B);
    }

    solve(X);

    sort(answer.begin(), answer.end());

    if(!answer.empty()) {
        for(int i=0; i<answer.size(); i++) cout << answer[i] << " ";
        cout << '\n';
    }
    else {
        cout << "-1\n";
    }

    return 0;
}