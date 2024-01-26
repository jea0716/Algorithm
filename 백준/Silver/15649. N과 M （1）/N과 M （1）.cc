#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool visited[10];

void DFS(int count) {
    if(count == M) {
        for(int i=0; i<M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            DFS(count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    DFS(0);
}