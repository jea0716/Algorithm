#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int K, N;
long long int dp[101];

long long int solve() {
    cin >> N;

    return dp[N];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> K;

    dp[1] = dp[2] = dp[3] = 1;
    for(int i=4; i<=100; i++) dp[i] = dp[i-2] + dp[i-3];

    while(K--) {
        cout << solve() << '\n';
    }

    return 0;
}