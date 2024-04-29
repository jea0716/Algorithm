#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string A, B;
int answer;
int dp[1001][1001];

void LCS() {
    for(int i=1; i<=A.length(); i++) {
        for(int j=1; j<=B.length(); j++) {
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[A.length()][B.length()] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> A >> B;

    LCS();

    return 0;
}