#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N;
int dp[1000001];

int main() {
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    cout << dp[N] << '\n';
}