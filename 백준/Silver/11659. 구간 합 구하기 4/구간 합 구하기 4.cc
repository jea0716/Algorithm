#include <iostream>

using namespace std;

int N, M;
int arr[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int tmp;
    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        cin >> tmp;
        arr[i] = tmp + arr[i-1];
    }

    int to, from;
    for(int i=0; i<M; i++) {
        cin >> to >> from;
        cout << arr[from] - arr[to-1] << "\n";
    }

    return 0;
}