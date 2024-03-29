#include <string>
#include <vector>

using namespace std;

int dp[60001];
int INF = 1000000007;

// 1 2 3 5

int solution(int n) {
    dp[1] = 1; dp[2] = 2;
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] % INF + dp[i-2] % INF) % INF;
    }
    int answer = dp[n];
    return answer;
}