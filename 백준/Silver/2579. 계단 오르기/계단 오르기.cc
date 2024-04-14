#include <iostream>

using namespace std;

int dp[301];
int arr[301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    for(int i=0; i<N; i++) cin >> arr[i];

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = arr[0] > arr[1] ? arr[0] + arr[2] : arr[1] + arr[2];

    for(int i=3; i<N; i++) {
        dp[i] = dp[i-2] > dp[i-3] + arr[i-1] ? dp[i-2] + arr[i] : dp[i-3] + arr[i-1] + arr[i];
    }

    cout << dp[N-1] << endl;

    return 0;
}