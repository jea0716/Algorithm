#include <iostream>

using namespace std;

int dp[1001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>=i; j--) {
            if(arr[i] > arr[j] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int answer = 0;
    
    for(int i=0; i<n; i++) { 
        if(answer < dp[i]) {
            answer = dp[i];
        }
    }

    cout << answer + 1 << "\n";

    return 0;
}