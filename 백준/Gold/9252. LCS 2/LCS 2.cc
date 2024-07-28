#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string A, B;
vector<vector<int>> dp;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> A >> B;

    dp.resize(A.size() + 1, vector<int>(B.size() + 1));

    for(int i=1; i<=A.length(); i++) {
        for(int j=1; j<=B.length(); j++) {
            if(A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j],  dp[i][j - 1]);
        }
    }

    cout << dp[A.length()][B.length()] << '\n';

    int i = A.length();
    int j = B.length();
    vector<char> answer;

    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i - 1][j]) {
            i--;
        } 
        else if(dp[i][j] == dp[i][j - 1]) {
            j--;
        }
        else {
            answer.push_back(A[i - 1]);
            i--;
            j--;
        }
    }

    for(int i=answer.size() - 1; i>=0; i--) {
        cout << answer[i];
    }
    cout << '\n';

    return 0;
}