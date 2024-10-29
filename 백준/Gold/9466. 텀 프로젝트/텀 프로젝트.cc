#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int K, N, ans;
vector<int> v;
vector<bool> visited;
vector<bool> done;
vector<int> impossible;

void DFS(int n) {
    visited[n] = true;
    int next = v[n];

    if(!visited[next]) DFS(next);
    else if(!done[next]) {
        for(int i=next; i != n; i = v[i]) {
            ans++;
        }
        ans++;
    }

    done[n] = true;
    return ;
}

void solve() {
    cin >> N;
    
    v.resize(N + 1);
    visited.resize(N + 1);
    done.resize(N + 1);
    for(int i=1; i<=N; i++) {
        visited[i] = false;
        done[i] = false;
    }

    ans = 0;

    for(int i=1; i<=N; i++) {
        cin >> v[i];
    }

    for(int i=1; i<=N; i++) {
        if(visited[i]) continue;
        DFS(i);
    }

    cout << N - ans << '\n';

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> K;

    while(K--) {
        solve();
    }

    return 0;
}   