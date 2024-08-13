#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int dp[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;

    for(int i=6; i<=N; i++) {
        if(!dp[i-1] || !dp[i-3] || !dp[i-4]) dp[i] = 1;
        else dp[i] = 0;
    }
    
    if(dp[N] == 1) cout << "SK\n";
    else cout << "CY\n";

    return 0;
}