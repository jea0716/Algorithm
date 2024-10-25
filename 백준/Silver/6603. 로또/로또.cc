#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int arr[13];
bool visited[13];
vector<int> v;

void DFS(int n, int x) {
    if(n == 6) {
        for(int i=0; i<N; i++) {
            if(visited[i]) cout << v[i] << ' ';
        }
        cout << '\n';
    }

    for(int i=0; i<N; i++) {
        if(!visited[i] && x < v[i]) {
            visited[i] = true;
            DFS(n + 1, v[i]);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    while(N != 0) {
        v.resize(N);
        for(int i=0; i<N; i++) {
            cin >> v[i];
            visited[i] = false;
        }

        sort(v.begin(), v.end());

        for(int i=0; i<=N-6; i++) {
            visited[i] = true;
            DFS(1, v[i]);
            visited[i] = false;
        }

        cout << '\n';
        cin >> N;
    }

    return 0;
}   