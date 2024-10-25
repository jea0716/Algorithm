#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, a, b;
vector<int> v[100001];
vector<bool> visited(100001, false);
vector<int> answer(100001, 0);

void DFS(int n) {
    visited[n] = true;

    for(int i=0; i<v[n].size(); i++) {
        if(!visited[v[n][i]]) {
            answer[v[n][i]] = n;
            DFS(v[n][i]);
        }
    }

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    for(int i=2; i<=N; i++) cout << answer[i] << ' ';
    cout << '\n';

    return 0;
}