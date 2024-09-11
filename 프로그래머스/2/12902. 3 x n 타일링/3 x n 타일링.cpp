#include <string>
#include <vector>

using namespace std;

long long dp[5001];
int MOD = 1000000007;

int solution(int n)
{
    dp[2] = 3;
    dp[4] = 11;
    for(int i=6; i<=n; i=i+2)
    {
        dp[i] = (dp[i - 2] * 4 - dp[i - 4]) % MOD;
        if(dp[i] < 0) dp[i] += MOD;
    }
    
    return dp[n];
}