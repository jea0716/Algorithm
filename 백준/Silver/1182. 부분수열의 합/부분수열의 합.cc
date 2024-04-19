#include <iostream>

using namespace std;

int s, e, answer;
int arr[21], tmp[21];
bool visited[21];

void DFS(int cnt, int n, int N, int M, int idx) {
    if(cnt == n) {
        int t = 0;
        for(int i=0; i<n; i++) {
            t += tmp[i];
        }
        if(t == M) answer++;
        return ;
    }

    for(int i=0; i<N; i++) {
        if(!visited[i] && i >= idx) {
            visited[i] = true;
            tmp[cnt] = arr[i];
            DFS(cnt + 1, n, N, M, i);
            visited[i] = false;
        }
    }
}

int main() {
    int N, M; cin >> N >> M;

    for(int i=0; i<N; i++) cin >> arr[i];

    for(int i=1; i<=N; i++) {
        DFS(0, i, N, M, 0);
    }

    cout << answer << "\n";

    return 0;
}