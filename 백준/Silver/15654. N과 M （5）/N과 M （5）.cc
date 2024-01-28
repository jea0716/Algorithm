#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int N_arr[10];
int visited[10];

void DFS(int count) {
    if(count == M) {
        for(int i=0; i<M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            arr[count] = N_arr[i];
            DFS(count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> N_arr[i];
    sort(N_arr, N_arr + N);
    DFS(0);
}