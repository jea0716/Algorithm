#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int N_arr[10];

void DFS(int n, int count) {
    if(count == M) {
        for(int i=0; i<M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for(int i=0; i<N; i++) {
        if(tmp == N_arr[i] || n > N_arr[i]) continue;
        arr[count] = N_arr[i];
        tmp = N_arr[i];
        DFS(N_arr[i], count + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> N_arr[i];
    sort(N_arr, N_arr + N);
    DFS(0, 0);
}