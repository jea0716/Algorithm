#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<pair<int, int> > v[100001];
bool visited[100001];
int selected, dist;

void dfs(int n, int cnt) {
    if(dist < cnt) {
        dist = cnt;
        selected = n;
    }

    for(int i=0; i<v[n].size(); i++) {
        int nx = v[n][i].first;
        int cost = v[n][i].second;
        if(!visited[nx]) {
            visited[nx] = true;
            dfs(nx, cnt + cost);
            visited[nx] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=1; i<=N; i++) {
        int s, e, c;
        cin >> s >> e;
        while(e != -1) {
            cin >> c;
            v[s].push_back({ e, c });
            cin >> e;
        }
    }

    visited[1] = true;
    dfs(1, 0);
    for(int i=0; i<100001; i++) visited[i] = false;
    dist = 0;
    visited[selected] = true;
    dfs(selected, 0);
    cout << dist << "\n";

    return 0;
}