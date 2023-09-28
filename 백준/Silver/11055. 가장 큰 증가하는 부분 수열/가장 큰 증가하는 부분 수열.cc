#include <iostream>

using namespace std;

int dp[1001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[j]) {
                dp[i] = dp[j] + arr[j];
            }
        }   
    }

    int answer = 0;
    for(int i=0; i<n; i++) { 
        if(answer < dp[i] + arr[i]) {
            answer = dp[i] + arr[i];
        }
    }

    cout << answer << "\n";

    return 0;
}