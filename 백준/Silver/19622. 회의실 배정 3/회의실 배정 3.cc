#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, S, E, C;

vector<vector<int>> v;
int dp[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> S >> E >> C;
        v.push_back({ S, E, C });
    }

    if(N == 1) {
        cout << v[0][2] << '\n';
        return 0;
    }

    dp[0] = v[0][2];
    dp[1] = max(dp[0], v[1][2]);

    for(int i=2; i<v.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i][2]);
    }

    cout << dp[N-1] << '\n';

    return 0;
}   