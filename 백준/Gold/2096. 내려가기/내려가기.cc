#include <iostream>
#include <algorithm>

using namespace std;

int min_dp[3], max_dp[3];

int main() {
    int n; cin >> n;

    int a, b, c, t1, t2, t3;
    cin >> min_dp[0] >> min_dp[1] >> min_dp[2];
    max_dp[0] = min_dp[0];
    max_dp[1] = min_dp[1];
    max_dp[2] = min_dp[2];

    for(int i=1; i<n; i++) {
        cin >> a >> b >> c;
        t1 = a + min(min_dp[0], min_dp[1]);
        t2 = b + min(min_dp[0], min(min_dp[1], min_dp[2]));
        t3 = c + min(min_dp[1], min_dp[2]);

        min_dp[0] = t1;
        min_dp[1] = t2;
        min_dp[2] = t3;

        t1 = a + max(max_dp[0], max_dp[1]);
        t2 = b + max(max_dp[0], max(max_dp[1], max_dp[2]));
        t3 = c + max(max_dp[1], max_dp[2]);

        max_dp[0] = t1;
        max_dp[1] = t2;
        max_dp[2] = t3;
    }

    int min_num = min(min_dp[0], min(min_dp[1], min_dp[2]));
    int max_num = max(max_dp[0], max(max_dp[1], max_dp[2]));

    cout << max_num << " " << min_num << "\n";

    return 0;
}