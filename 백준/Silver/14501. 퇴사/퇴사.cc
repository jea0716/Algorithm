#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dp[16];
int T[16];
int P[16];

int main()
{
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> T[i] >> P[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        if(i + T[i] <= n)
        {
            dp[i] = max(dp[i], dp[i+T[i]] + P[i]);
        }
        dp[i] = max(dp[i], dp[i+1]);
    }
    cout << dp[0] << "\n";
    return 0;
}