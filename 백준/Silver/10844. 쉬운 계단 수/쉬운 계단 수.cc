#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
const int MOD = 1e9;

int N;
int dp[101][11];

int main() {
    cin >> N;

    for(int i=1; i<10; i++) dp[1][i] = 1;
    dp[1][0] = 0;
    dp[1][10] = 9;

    for(int i=2; i<9; i++) dp[2][i] = 2;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][9] = 1;
    dp[2][10] = 17;

    for(int i=3; i<=100; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        dp[i][10] = (dp[i][0] + dp[i][9]) % MOD;
        for(int j=1; j<9; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            dp[i][10] = (dp[i][10] + dp[i][j]) % MOD;
        }
    }

    cout << dp[N][10] << '\n';

    return 0;
}