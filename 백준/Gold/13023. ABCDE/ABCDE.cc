#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct node {
    int area;
    bool arr[2001];
};

int N, M;
vector<int> v[2001];
bool check = false;

void solve(int k, int cur, vector<bool> &visited) {
    if(k == 4) {
        check = true;
        return;
    }

    for(int i=0; i<v[cur].size(); i++) {
        int next = v[cur][i];
        if(visited[next]) continue;
        visited[next] = 1;
        solve(k + 1, next, visited);
        visited[next] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    int a, b;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<N; i++) {
        vector<bool> visited(N, 0);
        visited[i] = 1;
        solve(0, i, visited);
        if(check) break;
    }

    if(check) cout << "1\n";
    else cout << "0\n";

    return 0;
}