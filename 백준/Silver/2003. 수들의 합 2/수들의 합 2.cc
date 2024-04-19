#include <iostream>

using namespace std;

int s, e, sum, cnt;
int arr[10002];

int main() {
    int N, M; cin >> N >> M;

    for(int i=0; i<N; i++) cin >> arr[i];

    sum = 0, e = 0;

    while(e <= N) {
        if(sum < M) {
            sum += arr[e++];
        }
        else if(sum > M) {
            sum -= arr[s++];
        }
        else {
            cnt++;
            sum += arr[e++];
        }
    }

    cout << cnt << "\n";

    return 0;
}