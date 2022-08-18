#include <iostream>

using namespace std;

int dp[100001][2];

void solve(){
    int n; cin >> n;
    int arr[n+1][2];
    for(int i=0; i<2; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[j][i];
        }
    }
    cout << dp[0][0] << " " << dp[0][1] << endl;
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    cout << dp[1][0] << " " << dp[1][1] << endl;
    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][1] + arr[i][0], dp[i-2][1] + arr[i][0]);
        dp[i][1] = max(dp[i-1][0] + arr[i][1], dp[i-2][0] + arr[i][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++) solve();
    return 0;
}