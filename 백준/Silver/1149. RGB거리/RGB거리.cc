#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, a, b, c, t1, t2, t3;
int dp[3];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> a >> b >> c;
        t1 = a + min(dp[1], dp[2]);
        t2 = b + min(dp[0], dp[2]);
        t3 = c + min(dp[0], dp[1]);

        dp[0] = t1;
        dp[1] = t2;
        dp[2] = t3;
    }

    cout << min(dp[0], min(dp[1], dp[2])) << endl;
    return 0;
}