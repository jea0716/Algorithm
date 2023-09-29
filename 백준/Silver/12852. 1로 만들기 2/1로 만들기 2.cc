#include <iostream>

using namespace std;

int dp[1000001];
int dp2[1000001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    dp[2] = 1; dp[3] = 1;
    dp2[1] = dp2[2] = dp2[3] = 1;

    int tmp;
    for(int i=4; i<=n; i++) {
        tmp = 999999;
        if(i % 3 == 0 && dp[i/3] < tmp) {
            tmp = dp[i/3];
            dp2[i] = i/3;
        }
        if(i % 2 == 0 && dp[i/2] < tmp) {
            tmp = dp[i/2];
            dp2[i] = i/2;
        }
        if(dp[i-1] < tmp) {
            tmp = dp[i-1];
            dp2[i] = i-1;
        }
        dp[i] = tmp + 1;
    }

    cout << dp[n] << "\n";
    int order = n;
    cout << order << " ";
    while(order != 1) {
        cout << dp2[order] << " ";
        order = dp2[order];
    }
    cout << "\n";

    return 0;
}