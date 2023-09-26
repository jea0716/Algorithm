#include <iostream>

using namespace std;

int dp[1001];

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++) {
        if(dp[i] > answer) answer = dp[i];
    }

    cout << answer + 1 << "\n";

    return 0;
}