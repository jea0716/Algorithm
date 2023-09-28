#include <iostream>

using namespace std;

int dp[3][1516];
int MOD = 1'000'000'007;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    dp[0][1] = 0;
    dp[0][2] = 1; dp[1][2] = 1; dp[2][2] = 0;

    for(int i=3; i<=n; i++) {
        dp[0][i] = (dp[2][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = (dp[2][i-1] + dp[0][i-1]) % MOD;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;
    }

    cout << dp[0][n] << "\n";

    return 0;
}