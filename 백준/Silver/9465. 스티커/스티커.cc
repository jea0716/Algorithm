#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T, N;
int map[2][100001];
int dp[2][100001];

int solve() {
    cin >> N;

    for(int i=0; i<2; i++) {
        for(int j=1; j<=N; j++) cin >> map[i][j];
    }

    int answer = max(map[0][1], map[1][1]);

    dp[0][1] = map[0][1];
    dp[1][1] = map[1][1];

    for(int i=2; i<=N; i++) {
        dp[0][i] = max(dp[1][i-1], max(dp[0][i-2], dp[1][i-2])) + map[0][i];
        dp[1][i] = max(dp[0][i-1], max(dp[0][i-2], dp[1][i-2])) + map[1][i];

        answer = max(answer, max(dp[0][i], dp[1][i]));
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;

    for(int i=0; i<T; i++) {
        cout <<  solve() << "\n";
    }

    return 0;
}