#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, dp[10001][4];

void solve() {
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;

    for(int i=3; i<=10000; i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    return ;
}

int main() {
    cin >> T;

    solve();

    for(int i=0; i<T; i++) {
        cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
    }

    return 0;
}