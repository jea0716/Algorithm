#include <iostream>

using namespace std;

int main() {
    int N, M; cin >> N >> M;

    int arr[N], answer = 987654321;
    for(int i=0; i<N; i++) cin >> arr[i];

    int s = 0, e = 0, sum = 0;

    while(e <= N) {
        if(sum < M) {
            sum += arr[e];
            e++;
        }
        else {
            if(e - s < answer) answer = e - s;
            sum -= arr[s];
            s++;
        }
    }

    if(answer == 987654321) answer = 0;
    cout << answer << "\n";

    return 0;
}