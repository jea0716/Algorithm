#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define INF pow(2, 31) - 1

int N;
int dp[501][501];
int mat[501][2];

int solve(int s, int e) {
    if(s == e) return 0;

    int &ret = dp[s][e];
    if(ret != -1) return ret;
    ret = INF;

    for(int i=s; i<e; i++) {
        ret = min(ret, solve(s, i) + solve(i + 1, e) + mat[s][0] * mat[i][1] * mat[e][1]);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> mat[i][0] >> mat[i][1];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, N - 1) << '\n';

    return 0;
}