#include <iostream>

using namespace std;

long long int dp[65][10];
long long int sum;

void solve(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        sum = 0;
        for(int j=0; j<10; j++){
            dp[i][j] = dp[i-1][j] + sum;
            sum += dp[i-1][j];
        }
    }
    cout << dp[n][9] << endl;
}

int main(){
    int n; cin >> n;
    for(int i=0; i<10; i++) dp[0][i] = 1;
    for(int i=0; i<n; i++) solve();
    return 0;
}