#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF 987654321

int T, K;
int dp[501][501];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> K;
        vector<int> v(K + 1, 0);
        vector<int> vSum(K + 1, 0);
        for(int i=1; i<=K; i++) {
            cin >> v[i];
            vSum[i] += vSum[i-1] + v[i];
        }

        for(int len=2; len<=K; len++) {
            for(int i=1; i<=K-len+1; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;

                for(int k=i; k<j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + vSum[j] - vSum[i-1]);
                }
            }
        }

        cout << dp[1][K] << '\n';

    }

    return 0;
}   