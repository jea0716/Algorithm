#include <iostream>

using namespace std;

int dp[222][222];
int MOD = 1000000000;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    for(int i=0; i<=m; i++) dp[0][i] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = ((dp[i-1][j] % MOD) + (dp[i][j-1] % MOD) % MOD);
        }
    }

    cout << dp[n][m] % MOD << "\n";

    return 0;
}