#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF 987654321

int N, K, tmp;
vector<int> v;
int dp[10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=1; i<=K; i++) { dp[i] = INF; }

    for(int i=0; i<N; i++) {
        for(int j=v[i]; j<=K; j++) {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }

    if(dp[K] == INF) cout << "-1\n";
    else cout << dp[K] << "\n";
 
    return 0;
}   