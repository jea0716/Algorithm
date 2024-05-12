#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    int arr[N];

    for(int i=0; i<N; i++) cin >> arr[i];

    int sum = 0, answer = 0;
    for(int i=N-1; i>=0; i--) {
        while(sum + arr[i] <= K) {
            sum += arr[i];
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}