#include <iostream>

using namespace std;

long long int dp[36];

int main(){
    int n; cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n+1; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j];
        }
    }
    cout << dp[n+1] << endl;
    return 0;
}